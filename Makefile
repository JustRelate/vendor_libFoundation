PROJECT_ROOT := $(shell cd ../..; pwd)

ifndef INSTALL_DIR
$(error INSTALL_DIR undefined)
endif
ifndef TARGET_OSTYPE
$(error TARGET_OSTYPE undefined)
endif
ifndef VERSION
$(error VERSION undefined)
endif

include $(PROJECT_ROOT)/Makefiles/Makefile.config

.PHONY: install
install:
	@$(call mkdir,$(INSTALL_DIR)/libFoundation)
	@$(call sync,common/$(VERSION)/,$(INSTALL_DIR)/libFoundation)
ifeq ($(TARGET_OSTYPE),NT)
	@$(call copy,$(TARGET_OSTYPE)/$(VERSION)/lib/Foundation.dll,$(INSTALL_DIR)/libFoundation/)
endif

