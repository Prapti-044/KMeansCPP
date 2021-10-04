#include <Rcpp.h>
#include "kmeans.h"
#include <iostream>
using namespace Rcpp;


//' Applies K-Means algorithm to the given data data.mat
//'
//' \code{applyKMeans} returns the the cluster centroids.
//'
//' @param dataMatrix Dataset of type matrix (List of double) and shape (n x d), where n is the number of observations and d is the dimension of the dataset.
//' @param K The number of clusters.
//' @param maxIter Maximum number of iterations of Kmeans clustering algorithm.
//' @return The centroids of the clusters.
//'
//'   For description of how KMeans clustering algorithm works, please see the following url.
//'   \url{https://en.wikipedia.org/wiki/K-means_clustering}
//' @examples
//' applyKMeans(as.matrix(iris[,-5]), 3, 300)
//' @export
// [[Rcpp::export]]
std::vector< std::vector<double> > applyKMeans(NumericMatrix dataMatrix, int K, int maxIter) {
  std::vector<Observation> points;
  for(int i = 0; i<dataMatrix.nrow(); i++) {
    std::vector<double> row;
    for(int j = 0; j<dataMatrix.ncol(); j++) {
      row.push_back(dataMatrix(i, j));
    }
    points.push_back(Observation(dataMatrix.ncol(), row));
  }
  return kMeansClustering(&points, K, maxIter);
}

