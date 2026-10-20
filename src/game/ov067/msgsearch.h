#ifndef GAME_OV067_MSGSEARCH_H
#define GAME_OV067_MSGSEARCH_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of msgsearch.c, prototypes copied from their definitions. */

struct MsgBank;
struct Strbuf;

#include "../ov067/msgsearch_types.h"
#include "../types.h"

MsgSearch *MSGSEARCH_Create(struct MsgBank **banks, u32 bankCount, u16 heapId);
void MSGSEARCH_Delete(MsgSearch *search);
u32 MSGSEARCH_Search(MsgSearch *search, u32 bankIndex, u32 unused, struct Strbuf *prefix, MsgSearchHit *hits, u32 maxHits);
int MSGSEARCH_PrefixMatches(struct Strbuf *prefix, struct Strbuf *text, u32 length);
/* END mkheaders: generated region */

#endif
