#!/bin/bash

maxParam=1
if [ $# -ne $maxParam ]
then
    echo "Maximum allowed args: $maxParam"
    echo "Given number of args: $#"
    exit
fi

screenBrightness=$1
if [ $screenBrightness == "max" ]
then screenBrightness=1
fi

monitors=`xrandr --current | grep -w connected`     # List all connected monitors
monitorPorts=$(echo $monitors | awk '{print $1}')   # Get only monitor names fom the grepped list

# Adjust the brightness in each monitor using the passed in brightness
for screen in ${monitorPorts}
do
    $(xrandr --output $screen --brightness $screenBrightness)
done