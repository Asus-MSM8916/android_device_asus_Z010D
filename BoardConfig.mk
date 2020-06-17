#
# Copyright (C) 2016 The CyanogenMod Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

# inherit from common msm8916-common
-include device/asus/msm8916-common/BoardConfigCommon.mk

DEVICE_PATH := device/asus/Z010D

# Assert
TARGET_OTA_ASSERT_DEVICE := Z010D,Z010DD,Z010_2,ASUS_Z010D,ASUS_Z010_2,ASUS_Z010DD

# Board
TARGET_BOARD_INFO_FILE := $(DEVICE_PATH)/board-info.txt

# Kernel
TARGET_KERNEL_SOURCE := kernel/asus/Z010D
TARGET_KERNEL_CONFIG := zc550kl-custom_defconfig

# Lights
TARGET_PROVIDES_LIBLIGHT := true

# Partitions
BOARD_SYSTEMIMAGE_PARTITION_SIZE := 2684354560
BOARD_USERDATAIMAGE_PARTITION_SIZE := 12530449408 # 12530465792 - 16384
BOARD_CACHEIMAGE_PARTITION_SIZE := 33554432

# Properties
TARGET_SYSTEM_PROP += $(DEVICE_PATH)/system.prop

# releasetools
TARGET_RELEASETOOLS_EXTENSIONS += $(DEVICE_PATH)/releasetools

# Init
TARGET_INIT_VENDOR_LIB := libinit_Z010D
TARGET_RECOVERY_DEVICE_MODULES := libinit_Z010D
