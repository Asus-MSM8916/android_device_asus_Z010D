#!/sbin/sh

cpu_id_file=/sys/devices/soc0/soc_id
cpu_id=`cat /sys/devices/soc0/soc_id`

# OpenGLES AEP is supported only by msm8939
# Remove it for the other targets
if [ -f "$cpu_id_file" ]; then
    case "$cpu_id" in
        "239" | "241" | "263" | "268" | "269" | "270" | "271")
            # Stub
            ;;
        *)
            rm -f /system/vendor/etc/permissions/android.hardware.opengles.aep.xml
            ;;
    esac
fi

if [ -f "$cpu_id_file" ]; then
    case "$cpu_id" in
        "239" | "241" | "263" | "268" | "269" | "270" | "271")
            rm -rf /system/system/etc/firmware
            cp -rf /tmp/install/Z010DD/system/* /system/system/
            ;;
        *)
            ;;
    esac
fi

exit 0
