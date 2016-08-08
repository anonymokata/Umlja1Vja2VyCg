# roman-numeral-kata

This kata allows for the addition and subtraction of Roman numerals. I chose to do this by converting each numeral to its integer value, doing the math, and then converting back.

The breakdown of tasks involved is as follows, where one depends on the next:  
`(add|subtract) -> convert numerals to integers -> convert each single character to its int value`

## Tech stack:  
Ubuntu 14.04 (Dockerfile can be found [here](https://github.com/rucker/docker-ubuntu/blob/master/Dockerfile))  
git  
gcc  
[check](https://libcheck.github.io)
