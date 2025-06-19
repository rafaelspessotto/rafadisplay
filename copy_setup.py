import shutil

def before_build(source, target, env):
    shutil.copy("src/User_Setup.h", ".pio/libdeps/esp32dev/TFT_eSPI/User_Setup.h")