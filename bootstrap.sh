#!/bin/bash
gcc tool/transport.c -o transport
./transport h instructions
./transport c instructions
./transport a instructions
