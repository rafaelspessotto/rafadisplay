import shutil

# Path to your custom User_Setup.h
src = "src/User_Setup.h"
# Path to the TFT_eSPI library User_Setup.h (adjust as needed)
dst = ".pio/libdeps/esp32dev/TFT_eSPI/User_Setup.h"

shutil.copyfile(src, dst)
print(f"*************************************************")
print(f"Copied pin config file {src} to {dst} ")
print(f"*************************************************")