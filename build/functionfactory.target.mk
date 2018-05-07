# This file is generated by gyp; do not edit.

TOOLSET := target
TARGET := functionfactory
DEFS_Debug := \
	'-DNODE_GYP_MODULE_NAME=functionfactory' \
	'-DUSING_UV_SHARED=1' \
	'-DUSING_V8_SHARED=1' \
	'-DV8_DEPRECATION_WARNINGS=1' \
	'-D_LARGEFILE_SOURCE' \
	'-D_FILE_OFFSET_BITS=64' \
	'-DBUILDING_NODE_EXTENSION' \
	'-DDEBUG' \
	'-D_DEBUG' \
	'-DV8_ENABLE_CHECKS'

# Flags passed to all source files.
CFLAGS_Debug := \
	-fPIC \
	-pthread \
	-Wall \
	-Wextra \
	-Wno-unused-parameter \
	-m64 \
	-g \
	-O0

# Flags passed to only C files.
CFLAGS_C_Debug :=

# Flags passed to only C++ files.
CFLAGS_CC_Debug := \
	-fno-rtti \
	-fno-exceptions \
	-std=gnu++0x

INCS_Debug := \
	-I/home/czy/.node-gyp/9.10.1/include/node \
	-I/home/czy/.node-gyp/9.10.1/src \
	-I/home/czy/.node-gyp/9.10.1/deps/uv/include \
	-I/home/czy/.node-gyp/9.10.1/deps/v8/include

DEFS_Release := \
	'-DNODE_GYP_MODULE_NAME=functionfactory' \
	'-DUSING_UV_SHARED=1' \
	'-DUSING_V8_SHARED=1' \
	'-DV8_DEPRECATION_WARNINGS=1' \
	'-D_LARGEFILE_SOURCE' \
	'-D_FILE_OFFSET_BITS=64' \
	'-DBUILDING_NODE_EXTENSION'

# Flags passed to all source files.
CFLAGS_Release := \
	-fPIC \
	-pthread \
	-Wall \
	-Wextra \
	-Wno-unused-parameter \
	-m64 \
	-O3 \
	-fno-omit-frame-pointer

# Flags passed to only C files.
CFLAGS_C_Release :=

# Flags passed to only C++ files.
CFLAGS_CC_Release := \
	-fno-rtti \
	-fno-exceptions \
	-std=gnu++0x

INCS_Release := \
	-I/home/czy/.node-gyp/9.10.1/include/node \
	-I/home/czy/.node-gyp/9.10.1/src \
	-I/home/czy/.node-gyp/9.10.1/deps/uv/include \
	-I/home/czy/.node-gyp/9.10.1/deps/v8/include

OBJS := \
	$(obj).target/$(TARGET)/src/functionfactory.o

# Add to the list of files we specially track dependencies for.
all_deps += $(OBJS)

# CFLAGS et al overrides must be target-local.
# See "Target-specific Variable Values" in the GNU Make manual.
$(OBJS): TOOLSET := $(TOOLSET)
$(OBJS): GYP_CFLAGS := $(DEFS_$(BUILDTYPE)) $(INCS_$(BUILDTYPE))  $(CFLAGS_$(BUILDTYPE)) $(CFLAGS_C_$(BUILDTYPE))
$(OBJS): GYP_CXXFLAGS := $(DEFS_$(BUILDTYPE)) $(INCS_$(BUILDTYPE))  $(CFLAGS_$(BUILDTYPE)) $(CFLAGS_CC_$(BUILDTYPE))

# Suffix rules, putting all outputs into $(obj).

$(obj).$(TOOLSET)/$(TARGET)/%.o: $(srcdir)/%.cpp FORCE_DO_CMD
	@$(call do_cmd,cxx,1)

# Try building from generated source, too.

$(obj).$(TOOLSET)/$(TARGET)/%.o: $(obj).$(TOOLSET)/%.cpp FORCE_DO_CMD
	@$(call do_cmd,cxx,1)

$(obj).$(TOOLSET)/$(TARGET)/%.o: $(obj)/%.cpp FORCE_DO_CMD
	@$(call do_cmd,cxx,1)

# End of this set of suffix rules
### Rules for final target.
LDFLAGS_Debug := \
	-pthread \
	-rdynamic \
	-m64

LDFLAGS_Release := \
	-pthread \
	-rdynamic \
	-m64

LIBS :=

$(obj).target/functionfactory.node: GYP_LDFLAGS := $(LDFLAGS_$(BUILDTYPE))
$(obj).target/functionfactory.node: LIBS := $(LIBS)
$(obj).target/functionfactory.node: TOOLSET := $(TOOLSET)
$(obj).target/functionfactory.node: $(OBJS) FORCE_DO_CMD
	$(call do_cmd,solink_module)

all_deps += $(obj).target/functionfactory.node
# Add target alias
.PHONY: functionfactory
functionfactory: $(builddir)/functionfactory.node

# Copy this to the executable output path.
$(builddir)/functionfactory.node: TOOLSET := $(TOOLSET)
$(builddir)/functionfactory.node: $(obj).target/functionfactory.node FORCE_DO_CMD
	$(call do_cmd,copy)

all_deps += $(builddir)/functionfactory.node
# Short alias for building this executable.
.PHONY: functionfactory.node
functionfactory.node: $(obj).target/functionfactory.node $(builddir)/functionfactory.node

# Add executable to "all" target.
.PHONY: all
all: $(builddir)/functionfactory.node

