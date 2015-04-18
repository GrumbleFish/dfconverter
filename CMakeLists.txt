PROJECT (dfconverter)

FILE(GLOB MC_CPPS libanvil/*.c*)
FILE(GLOB TAG_CPPS libanvil/tag/*.c*)

SET(PROJECT_SRCS
	dfconverter.cpp
	${MC_CPPS}
	${TAG_CPPS}
)

FILE(GLOB MC_HPPS libanvil/*.h*)
FILE(GLOB TAG_HPPS libanvil/tag/*.h*)

SET(PROJECT_HDRS
	${MC_HPPS}
	${TAG_HPPS}
)

SET(PROJECT_LIBS
	zlib.lib
)
DFHACK_PLUGIN(dfconverter ${PROJECT_SRCS} ${PROJECT_HDRS} LINK_LIBRARIES ${PROJECT_LIBS})
