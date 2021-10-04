test_that("Output shapes are correct", {
  K.list <- 3:5
  for(K in K.list) {
    result <- applyKMeans(as.matrix(iris[,-5]), K, 300)

    expect_type(result, "list")
    for(i in lengths(result)) {
      expect_equal(i,4)
    }
  }
})
