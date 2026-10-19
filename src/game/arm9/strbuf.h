#ifndef GAME_ARM9_STRBUF_H
#define GAME_ARM9_STRBUF_H

/* Public functions of strbuf.c, prototypes copied from their definitions. */

struct Strbuf;

void STRBUF_SetEosChar(u16 eosChar);
struct Strbuf *STRBUF_Create(u32 capacity, u32 heapId);
void STRBUF_Delete(struct Strbuf *strbuf);
void STRBUF_Clear(struct Strbuf *strbuf);
void STRBUF_Copy(struct Strbuf *dst, struct Strbuf *src);
struct Strbuf *STRBUF_Clone(struct Strbuf *src, u32 heapId);
int STRBUF_IsEqual(struct Strbuf *lhs, struct Strbuf *rhs);
u16 STRBUF_GetLength(struct Strbuf *strbuf);
void STRBUF_Truncate(struct Strbuf *strbuf, u32 newLength);
void STRBUF_SetString(struct Strbuf *strbuf, const u16 *srcChars);
void STRBUF_SetStringN(struct Strbuf *strbuf, const u16 *srcChars, u32 charCount);
void STRBUF_SetChars(struct Strbuf *strbuf, const void *srcChars, u32 charCount);
void STRBUF_ToChars(struct Strbuf *strbuf, u16 *out, u32 maxChars);
u16 *STRBUF_GetChars(struct Strbuf *strbuf);
u16 STRBUF_GetEosChar(void);
void STRBUF_Append(struct Strbuf *dst, struct Strbuf *src);
void STRBUF_AppendChar(struct Strbuf *strbuf, u16 ch);

#endif
