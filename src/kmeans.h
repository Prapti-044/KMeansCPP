#ifndef KMEANS_H
#define KMEANS_H

#include <vector>
#include <random>

struct Observation {
  std::vector<double> values;
  int dim;
  int cluster;
  double minDist;

  Observation(int);
  Observation(int, std::vector<double>);

  double distance(Observation);
};
std::vector< std::vector<double> > kMeansClustering(std::vector<Observation>*, int, int);
#endif // KMEANS_H
