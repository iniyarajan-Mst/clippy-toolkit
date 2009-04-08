OBJECTS=Search
TARGET=Search.dylib
ENTRYPOINT=SearchInitialize



COMPILER=arm-apple-darwin9-gcc

LDFLAGS= \
		-dynamiclib \
		-Wall -Werror \
		-framework CoreFoundation -framework Foundation -framework UIKit \
		-lclippy -lobjc \
		-multiply_defined suppress

CFLAGS= \
		-c \
		-I/var/sdk/include -I/var/include \
		-fno-common \
		-g0 -O2 \
		-std=c99

all:	$(TARGET)

clean:
		rm -f $(OBJECTS) $(TARGET)
		rm -rf package

%:	%.m
		$(COMPILER) $(CFLAGS) $< -o $@

$(TARGET): $(OBJECTS)
		$(COMPILER) $(LDFLAGS) -init _$(ENTRYPOINT) -o $@ $^
		ldid -S $@
		
package: $(TARGET) control
		rm -rf package
		mkdir -p package/DEBIAN
		cp -a control package/DEBIAN
		mkdir -p package/Library/Clippy/Plugins
		cp -a $(TARGET) package/Library/Clippy/Plugins
		dpkg-deb -b package $(shell grep ^Package: control | cut -d ' ' -f 2)_$(shell grep ^Version: control | cut -d ' ' -f 2)_iphoneos-arm.deb
		
install: package
		dpkg -i $(shell grep ^Package: control | cut -d ' ' -f 2)_$(shell grep ^Version: control | cut -d ' ' -f 2)_iphoneos-arm.deb
