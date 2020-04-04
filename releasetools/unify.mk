UNIFY_PATH := device/asus/Z010D/releasetools


PRODUCT_COPY_FILES += \
		$(UNIFY_PATH)/install.asus.sh:install/bin/install.asus.sh
$(shell mkdir -p  $(UNIFY_PATH)/../../../../out/target/product/Z010D/install/Z010DD/system)
$(shell cp -rf $(UNIFY_PATH)/system/*  $(UNIFY_PATH)/../../../../out/target/product/Z010D/install/Z010DD/system)
