cmake_minimum_required(VERSION 3.3)
project(DP_Learning)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES findNoofCoins.cpp longestIncreasingSubsequence.cpp LongestIncSubSequence.cpp kadane.cpp FibonacciModified.cpp
        FFTMultiplication.cpp coinchange.cpp  bignum.cpp  candies.cpp  stocks.cpp  redjohn.cpp marshrect.cpp marshrect.h hrequal.cpp hrequal.h hrknalsack.cpp hrknalsack.h)
add_executable(DP_Learning ${SOURCE_FILES})