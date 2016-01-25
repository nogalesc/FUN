#!/bin/bash

echo "Converting all odt files to pdf in this dir"
libreoffice --headless --convert-to pdf *.odt

