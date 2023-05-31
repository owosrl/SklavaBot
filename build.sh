#!/bin/sh

CMAKE_FLAGS="-G Ninja"

export CXX=clang++
export CC=clang

cmake $CMAKE_FLAGS .
ninja
