#This makefile is based off the makefile from the TDD book

#Set this to @ to keep the makefile quiet
SILENCE = @

#---- Outputs ----#
COMPONENT_NAME = BookCode_CppUTest

#--- Inputs ----#
CPP_PLATFORM = Gcc
PROJECT_HOME_DIR = .

SRC_DIRS = \
	Source/LedDriver \

TEST_SRC_DIRS = \
	Testing/Tests \


	
INCLUDE_DIRS =\
  .\
  $(CPPUTEST_HOME)/include\
  include/LedDriver\

MOCKS_SRC_DIRS = \
	mocks\
	
CPPUTEST_WARNINGFLAGS = -Wall -Wswitch-default -Werror 
#CPPUTEST_CFLAGS = -std=c89 
CPPUTEST_CFLAGS += -Wall -Wstrict-prototypes -pedantic
LD_LIBRARIES = -lpthread
	
  
ifeq ($(CPPUTEST_HOME),)
$(info CPPUTEST_HOME not set! See README.txt)
else  
include $(CPPUTEST_HOME)/build/MakefileWorker.mk
endif