#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=mkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/mplabx.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/mplabx.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../../src/can.c ../../src/logger.c ../../src/main.c ../../src/nodeman.c ../../src/spi.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1445274692/can.o ${OBJECTDIR}/_ext/1445274692/logger.o ${OBJECTDIR}/_ext/1445274692/main.o ${OBJECTDIR}/_ext/1445274692/nodeman.o ${OBJECTDIR}/_ext/1445274692/spi.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1445274692/can.o.d ${OBJECTDIR}/_ext/1445274692/logger.o.d ${OBJECTDIR}/_ext/1445274692/main.o.d ${OBJECTDIR}/_ext/1445274692/nodeman.o.d ${OBJECTDIR}/_ext/1445274692/spi.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1445274692/can.o ${OBJECTDIR}/_ext/1445274692/logger.o ${OBJECTDIR}/_ext/1445274692/main.o ${OBJECTDIR}/_ext/1445274692/nodeman.o ${OBJECTDIR}/_ext/1445274692/spi.o

# Source Files
SOURCEFILES=../../src/can.c ../../src/logger.c ../../src/main.c ../../src/nodeman.c ../../src/spi.c

# Pack Options 
PACK_COMPILER_OPTIONS=-I ${DFP_DIR}/include
PACK_COMMON_OPTIONS=-B ${DFP_DIR}/gcc/dev/at90can128



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/mplabx.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=AT90CAN128
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1445274692/can.o: ../../src/can.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1445274692" 
	@${RM} ${OBJECTDIR}/_ext/1445274692/can.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445274692/can.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=at90can128 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -I"../../inc" -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/_ext/1445274692/can.o.d" -MT "${OBJECTDIR}/_ext/1445274692/can.o.d" -MT ${OBJECTDIR}/_ext/1445274692/can.o  -o ${OBJECTDIR}/_ext/1445274692/can.o ../../src/can.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1445274692/logger.o: ../../src/logger.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1445274692" 
	@${RM} ${OBJECTDIR}/_ext/1445274692/logger.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445274692/logger.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=at90can128 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -I"../../inc" -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/_ext/1445274692/logger.o.d" -MT "${OBJECTDIR}/_ext/1445274692/logger.o.d" -MT ${OBJECTDIR}/_ext/1445274692/logger.o  -o ${OBJECTDIR}/_ext/1445274692/logger.o ../../src/logger.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1445274692/main.o: ../../src/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1445274692" 
	@${RM} ${OBJECTDIR}/_ext/1445274692/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445274692/main.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=at90can128 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -I"../../inc" -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/_ext/1445274692/main.o.d" -MT "${OBJECTDIR}/_ext/1445274692/main.o.d" -MT ${OBJECTDIR}/_ext/1445274692/main.o  -o ${OBJECTDIR}/_ext/1445274692/main.o ../../src/main.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1445274692/nodeman.o: ../../src/nodeman.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1445274692" 
	@${RM} ${OBJECTDIR}/_ext/1445274692/nodeman.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445274692/nodeman.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=at90can128 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -I"../../inc" -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/_ext/1445274692/nodeman.o.d" -MT "${OBJECTDIR}/_ext/1445274692/nodeman.o.d" -MT ${OBJECTDIR}/_ext/1445274692/nodeman.o  -o ${OBJECTDIR}/_ext/1445274692/nodeman.o ../../src/nodeman.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1445274692/spi.o: ../../src/spi.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1445274692" 
	@${RM} ${OBJECTDIR}/_ext/1445274692/spi.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445274692/spi.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=at90can128 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -I"../../inc" -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/_ext/1445274692/spi.o.d" -MT "${OBJECTDIR}/_ext/1445274692/spi.o.d" -MT ${OBJECTDIR}/_ext/1445274692/spi.o  -o ${OBJECTDIR}/_ext/1445274692/spi.o ../../src/spi.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
else
${OBJECTDIR}/_ext/1445274692/can.o: ../../src/can.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1445274692" 
	@${RM} ${OBJECTDIR}/_ext/1445274692/can.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445274692/can.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=at90can128 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -I"../../inc" -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/_ext/1445274692/can.o.d" -MT "${OBJECTDIR}/_ext/1445274692/can.o.d" -MT ${OBJECTDIR}/_ext/1445274692/can.o  -o ${OBJECTDIR}/_ext/1445274692/can.o ../../src/can.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1445274692/logger.o: ../../src/logger.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1445274692" 
	@${RM} ${OBJECTDIR}/_ext/1445274692/logger.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445274692/logger.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=at90can128 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -I"../../inc" -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/_ext/1445274692/logger.o.d" -MT "${OBJECTDIR}/_ext/1445274692/logger.o.d" -MT ${OBJECTDIR}/_ext/1445274692/logger.o  -o ${OBJECTDIR}/_ext/1445274692/logger.o ../../src/logger.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1445274692/main.o: ../../src/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1445274692" 
	@${RM} ${OBJECTDIR}/_ext/1445274692/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445274692/main.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=at90can128 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -I"../../inc" -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/_ext/1445274692/main.o.d" -MT "${OBJECTDIR}/_ext/1445274692/main.o.d" -MT ${OBJECTDIR}/_ext/1445274692/main.o  -o ${OBJECTDIR}/_ext/1445274692/main.o ../../src/main.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1445274692/nodeman.o: ../../src/nodeman.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1445274692" 
	@${RM} ${OBJECTDIR}/_ext/1445274692/nodeman.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445274692/nodeman.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=at90can128 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -I"../../inc" -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/_ext/1445274692/nodeman.o.d" -MT "${OBJECTDIR}/_ext/1445274692/nodeman.o.d" -MT ${OBJECTDIR}/_ext/1445274692/nodeman.o  -o ${OBJECTDIR}/_ext/1445274692/nodeman.o ../../src/nodeman.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1445274692/spi.o: ../../src/spi.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1445274692" 
	@${RM} ${OBJECTDIR}/_ext/1445274692/spi.o.d 
	@${RM} ${OBJECTDIR}/_ext/1445274692/spi.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=at90can128 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -I"../../inc" -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/_ext/1445274692/spi.o.d" -MT "${OBJECTDIR}/_ext/1445274692/spi.o.d" -MT ${OBJECTDIR}/_ext/1445274692/spi.o  -o ${OBJECTDIR}/_ext/1445274692/spi.o ../../src/spi.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/mplabx.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mmcu=at90can128 ${PACK_COMMON_OPTIONS}  -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2 -D__$(MP_PROCESSOR_OPTION)__  -Wl,-Map="dist/${CND_CONF}/${IMAGE_TYPE}/mplabx.${IMAGE_TYPE}.map"    -o dist/${CND_CONF}/${IMAGE_TYPE}/mplabx.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}      -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_SIMULATOR=1 -Wl,--gc-sections -Wl,--start-group  -Wl,-lm -Wl,--end-group 
	
	
	
	
	
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/mplabx.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mmcu=at90can128 ${PACK_COMMON_OPTIONS}  -D__$(MP_PROCESSOR_OPTION)__  -Wl,-Map="dist/${CND_CONF}/${IMAGE_TYPE}/mplabx.${IMAGE_TYPE}.map"    -o dist/${CND_CONF}/${IMAGE_TYPE}/mplabx.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}      -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION) -Wl,--gc-sections -Wl,--start-group  -Wl,-lm -Wl,--end-group 
	${MP_CC_DIR}/avr-objcopy -O ihex "dist/${CND_CONF}/${IMAGE_TYPE}/mplabx.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}" "dist/${CND_CONF}/${IMAGE_TYPE}/mplabx.${IMAGE_TYPE}.hex"
	
	
	
	
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell "${PATH_TO_IDE_BIN}"mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
