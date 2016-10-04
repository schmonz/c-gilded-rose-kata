#!/bin/sh

make \
	&& ./GildedRoseUnitTests \
	&& ./GildedRoseTextTests > actual.txt \
	&& colordiff -u characterization.txt actual.txt
