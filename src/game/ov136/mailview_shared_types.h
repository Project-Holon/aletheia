#ifndef MAILVIEW_SHARED_TYPES_H
#define MAILVIEW_SHARED_TYPES_H

#include "mail_types.h"

struct DispVram;

/* Opaque types of callees in other files. */
struct Bmp;

struct Cfg;

struct DispConfig { u32 w[4]; };

struct BgTemplate { u32 w[8]; };

#endif
