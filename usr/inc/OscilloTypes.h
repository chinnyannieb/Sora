#ifndef _OSCILLO_TYPES_H
#define _OSCILLO_TYPES_H

#include "soratypes.h"

typedef enum _SORA_OSCILLO_DATA_TYPE
{
    DATA_TYPE_UNKNOWN = 0,
    DATA_TYPE_COMMAND,
    DATA_TYPE_COMPLEX8,
    DATA_TYPE_COMPLEX16,
    DATA_TYPE_COMPLEX32,
    DATA_TYPE_REAL,
    DATA_TYPE_BYTE,
    DATA_TYPE_TEXT,
    DATA_TYPE_PLANAR,
    DATA_TYPE_SPECTRAL,
    DATA_TYPE_TOPOGRAPHIC,
    DATA_TYPE_NOISE,
    DATA_TYPE_COUNT
} SORA_OSCILLO_DATA_TYPE;

const static char *g_rgDataTypeName[DATA_TYPE_COUNT] =
{
	"Unknown",
	"Command",
	"Complex8",
	"Complex16",
	"Complex32",
	"Real",
	"Byte",
	"Text",
    "Planar",
    "Spectral",
    "Topographic"
};

typedef enum _SORA_OSCILLO_COMMAND_TYPE
{
    SORA_COMMAND_RESET = 0,
    SORA_COMMAND_OVERVIEW_SETTIME,
    SORA_COMMAND_OVERVIEW_SETLENGTH,
    SORA_COMMAND_ALIGN,
    SORA_COMMAND_ZOOM_STARTDRAGGING,
    SORA_COMMAND_ZOOM_ENDDRAGGING,
    SORA_COMMAND_ZOOM_ONDRAGGING,
    SORA_COMMAND_ZOOM_RESET,
    SORA_COMMAND_TICKER_RATE
} SORA_OSCILLO_COMMAND_TYPE;

typedef struct _SORA_OSCILLO_COMMAND
{
    SORA_OSCILLO_COMMAND_TYPE CmdType;
    int nCmdParam;
} SORA_OSCILLO_COMMAND;

typedef struct _SORA_OSCILLO_DATA
{
    SORA_OSCILLO_DATA_TYPE DataType;
    union
    {
        COMPLEX8 comp8;
        COMPLEX16 comp16;
        COMPLEX32 comp32;
        double dbl;
        BYTE bt;
        char *text;
        SORA_OSCILLO_COMMAND cmd;
    };
    int nTime;
} SORA_OSCILLO_DATA;

const SORA_OSCILLO_DATA C_SORA_COMMAND_RESET = { DATA_TYPE_COMMAND, { SORA_COMMAND_RESET, 0 }, 0 };

enum OSCILLO_GRAPH_TYPE
{
    GRAPH_TYPE_CONSTEL = 0,
    GRAPH_TYPE_WAVE,
    GRAPH_TYPE_BIT,
    GRAPH_TYPE_BYTE,
    GRAPH_TYPE_TEXT,
    GRAPH_TYPE_OVERVIEW,
    GRAPH_TYPE_PLANAR,
    GRAPH_TYPE_SPECTRAL,
    GRAPH_TYPE_TOPOGRAPHIC,
    GRAPH_TYPE_SUMMARY,
    GRAPH_TYPE_UNKNOWN
};

#endif 