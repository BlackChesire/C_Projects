#!/bin/bash

for i in {1..50000} ; do
	./prog | grep "fail"
done
