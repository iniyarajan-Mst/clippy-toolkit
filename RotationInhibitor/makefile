OBJECTS=Toggle
TARGET=fs/Library/MobileSubstrate/DynamicLibraries/RotationInhibitor.dylib
ENTRYPOINT=ToggleInit



COMPILER=arm-apple-darwin9-gcc

LDFLAGS= \
		-dynamiclib \
		-Wall -Werror \
		-framework CoreFoundation -framework Foundation -framework UIKit -framework GraphicsServices -lobjc -lsubstrate \
		-F/System/Library/PrivateFrameworks \
		-multiply_defined suppress

CFLAGS= -I/Projects/Headers -I/var/sdk/include -I/var/include \
		-fno-common \
		-g0 -O2 \
		-std=c99

all:	$(TARGET)

clean:
		rm -f $(OBJECTS) $(TARGET)
		rm -rf package

%:	%.m Common.h
		$(COMPILER) -c $(CFLAGS) -include Common.h $(filter %.m,$^) -o $@

$(TARGET): $(OBJECTS)
		$(COMPILER) $(LDFLAGS) -init _$(ENTRYPOINT) -o $@ $^
		strip -x $@
		ldid -S $@
		
package: $(TARGET) control
		rm -rf package
		mkdir -p package/DEBIAN
		cp -a control preinst prerm package/DEBIAN
		cp -a fs/* package
		dpkg-deb -b package $(shell grep ^Package: control | cut -d ' ' -f 2)_$(shell grep ^Version: control | cut -d ' ' -f 2)_iphoneos-arm.deb
		
install: package
		dpkg -i $(shell grep ^Package: control | cut -d ' ' -f 2)_$(shell grep ^Version: control | cut -d ' ' -f 2)_iphoneos-arm.deb
		respring