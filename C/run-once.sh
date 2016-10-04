#!/bin/sh

make \
	&& ./GildedRoseTextTests > actual.txt \
	&& colordiff -u characterization.txt actual.txt
