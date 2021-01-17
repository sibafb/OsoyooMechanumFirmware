# Please pass the path for arduino.exe before starting/arduino.exeへのパスを通してから起動してください
# rosrun osoyoo_mechanum_firmware write.sh

echo "writing arduino"
echo "connect arduino on USB"

cd `dirname ${0}`/../

# ARDUINO(1) Manual Page 
# https://github.com/arduino/Arduino/blob/1.6.4/build/shared/manpage.adoc

# arduino  arduino --verify [osoyoo_mechanum_firmware.ino]
arduino --upload [osoyoo_mechanum_firmware.ino]

