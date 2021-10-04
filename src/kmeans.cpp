#include "kmeans.h"

Observation::Observation(int dim) : dim(dim), values(std::vector<double>(dim)),cluster(-1), minDist(__DBL_MAX__) {}
Observation::Observation(int dim, std::vector<double> values) : Observation(dim) {
  for(int i = 0; i<dim && i<values.size(); i++) {
    this->values[i] = values[i];
  }
}
double Observation::distance(Observation p) {
  double sum = 0;
  for(int i = 0; i<values.size(); i++) {
    sum += (p.values[i] - values[i]) * (p.values[i] - values[i]);
  }
  return sum;
}

std::vector< std::vector<double> > kMeansClustering(std::vector<Observation>* points, int k, int iterMax) {
  int n = points->size();

  std::vector<Observation> centroids;
  for (int i = 0; i < k; ++i) {
    centroids.push_back(points->at(rand() % n));
  }

  for (int i = 0; i < iterMax; ++i) {
    for (std::vector<Observation>::iterator c = begin(centroids); c != end(centroids);
    ++c) {
      int clusterId = c - begin(centroids);

      for (std::vector<Observation>::iterator it = points->begin();
           it != points->end(); ++it) {
        Observation p = *it;
        double dist = c->distance(p);
        if (dist < p.minDist) {
          p.minDist = dist;
          p.cluster = clusterId;
        }
        *it = p;
      }
    }

    std::vector<int> nPoints;
    std::vector< std::vector<double> > sum;
    for (int j = 0; j < k; ++j) {
      nPoints.push_back(0);
      sum.push_back(std::vector<double>((*points)[0].values.size()));
    }

    for (std::vector<Observation>::iterator it = points->begin(); it != points->end();
    ++it) {
      int clusterId = it->cluster;
      nPoints[clusterId] += 1;
      for(int d = 0; d<sum[clusterId].size(); d++) {
        sum[clusterId][d] += it->values[d];
      }

      it->minDist = __DBL_MAX__;  // reset distance
    }
    // Compute new centroids
    for (std::vector<Observation>::iterator c = begin(centroids); c != end(centroids);
    ++c) {
      int clusterId = c - begin(centroids);
      for(int d = 0; d<sum[clusterId].size(); d++) {
        c->values[d] = sum[clusterId][d] / nPoints[clusterId];
      }
    }
  }
  std::vector< std::vector<double> > centroidsRet;
  for (int i = 0; i < k; ++i) {
    centroidsRet.push_back(centroids[i].values);
  }
  return centroidsRet;
}
