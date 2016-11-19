/*
   Copyright (c) 2013, The Linux Foundation. All rights reserved.
   Copyright (C) 2016 The CyanogenMod Project.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "vendor_init.h"
#include "property_service.h"
#include "log.h"
#include "util.h"

#define ISMATCH(a,b)    (!strncmp(a,b,PROP_VALUE_MAX))

char const *device;
char const *family;
char const *heapstartsize;
char const *heapgrowthlimit;
char const *heapsize;
char const *heapminfree;

void vendor_load_properties()
{

    char b_description[PROP_VALUE_MAX], b_fingerprint[PROP_VALUE_MAX];
    char p_carrier[PROP_VALUE_MAX], p_device[PROP_VALUE_MAX], p_model[PROP_VALUE_MAX];
    char platform[PROP_VALUE_MAX];
    int rc;

    rc = property_get("ro.board.platform", platform);
    if (!rc || !ISMATCH(platform, ANDROID_TARGET))
        return;

    /* Device Setting */
    family = "WW_Phone";
    device = "Z010D";

    /* Heap Setting */
    heapstartsize = "8m";
    heapgrowthlimit = "192m";
    heapsize = "512m";
    heapminfree = "512k";

    sprintf(b_description, "%s-user 6.0.1 MMB29P 13.8.26.46-20160812 release-keys", family);
    sprintf(b_fingerprint, "asus/%s/ASUS_%s:6.0.1/MMB29P/13.8.26.46-20160812:user/release-keys", family, device);
    sprintf(p_model, "ASUS_%s", device);
    sprintf(p_device, "ASUS_%s_1", device);
    sprintf(p_carrier, "US-ASUS_%s-%s", device, family);

    property_set("ro.build.description", b_description);
    property_set("ro.build.fingerprint", b_fingerprint);
    property_set("ro.product.carrier", p_carrier);
    property_set("ro.product.device", p_device);
    property_set("ro.product.model", p_model);

    /* Heap Set */
    property_set("dalvik.vm.heapstartsize", heapstartsize);
    property_set("dalvik.vm.heapgrowthlimit", heapgrowthlimit);
    property_set("dalvik.vm.heapsize", heapsize);
    property_set("dalvik.vm.heaptargetutilization", "0.75");
    property_set("dalvik.vm.heapminfree", heapminfree);
    property_set("dalvik.vm.heapmaxfree", "2m");

    INFO("Setting build properties for %s device of %s family\n", device, family);
}