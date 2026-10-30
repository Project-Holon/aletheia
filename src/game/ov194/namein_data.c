/*
 * file:     namein_data.c
 * unit:     yes
 * function: NAMEIN_GRAPHIC_LoadArcMember, NAMEIN_GRAPHIC_FreeMember, NAMEIN_GRAPHIC_CreateMembers, NAMEIN_GRAPHIC_DeleteMembers, NAMEIN_GRAPHIC_GetWord, NAMEIN_GRAPHIC_GetGridWidth, NAMEIN_GRAPHIC_GetGridHeight, NAMEIN_GRAPHIC_GetGridCell, NAMEIN_GRAPHIC_LoadCharMember, NAMEIN_GRAPHIC_FreeHandle, NAMEIN_GRAPHIC_GetTableCount, NAMEIN_GRAPHIC_CopyTableEntries, NAMEIN_GRAPHIC_PickTable8, NAMEIN_GRAPHIC_PickTableE, NAMEIN_GRAPHIC_PickTable14, NAMEIN_GRAPHIC_FindTableIndex, NAMEIN_GRAPHIC_CompareEntry, NAMEIN_GRAPHIC_LoadPairMember, NAMEIN_GRAPHIC_FreePairMember, NAMEIN_GRAPHIC_GetPairCount, NAMEIN_GRAPHIC_GetPairEntry, NAMEIN_GRAPHIC_NextPairChar, NAMEIN_GRAPHIC_IsNameCharValid
 * address:  0x021F4D20
 * region:   ov194
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from namein_graphic_p03.c by tools/splitfile.py.
 *
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   GFL_HEAP_Free 0x020307B0 arm
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   d_021F5798 0x021F5798 data a4
 *   WORDSET_CopyString 0x0201F41C thumb
 *   STRBUF_GetEosChar 0x02045A98 arm
 *   ARC_UTIL_LoadMember 0x0204A1BC arm
 */
#include "../types.h"
#include "../version.h"

#include "../arm9/mi_memory.h"

#include "../arm9/gfl_heap_wrap.h"


#include "../arm9/arc_util.h"

#include "../arm9/wordset.h"

#include "../arm9/strbuf.h"

void *NAMEIN_GRAPHIC_LoadArcMember(u32 a, u16 b);

void NAMEIN_GRAPHIC_FreeMember(void *p);

void **NAMEIN_GRAPHIC_CreateMembers(u16 heap);

void NAMEIN_GRAPHIC_DeleteMembers(void **p);

void *NAMEIN_GRAPHIC_GetWord(void *const *p, u32 i);

u16 NAMEIN_GRAPHIC_GetGridWidth(const u16 *p);

u16 NAMEIN_GRAPHIC_GetGridHeight(const u16 *p);

u32 NAMEIN_GRAPHIC_GetGridCell(u8 *p, u16 a, u16 b);

void *NAMEIN_GRAPHIC_LoadCharMember(int a, u16 b);

void NAMEIN_GRAPHIC_FreeHandle(void *p);

u16 NAMEIN_GRAPHIC_GetTableCount(const u16 *p);

void NAMEIN_GRAPHIC_CopyTableEntries(const char *p,int i,u16 *dst,u32 n,u8 *count);

int NAMEIN_GRAPHIC_PickTable8(const char *p, int idx, unsigned short *tab, int val, unsigned char *out);

int NAMEIN_GRAPHIC_PickTableE(const char *p, int idx, unsigned short *tab, int val, unsigned char *out);

int NAMEIN_GRAPHIC_PickTable14(char *p, int index, unsigned short *table, unsigned n, unsigned char *out);

u16 NAMEIN_GRAPHIC_FindTableIndex(const char *p,const u16 *b);

int NAMEIN_GRAPHIC_CompareEntry(const unsigned short *a, const unsigned short *b);

void *NAMEIN_GRAPHIC_LoadPairMember(u16 a);

void NAMEIN_GRAPHIC_FreePairMember(void *p);

int NAMEIN_GRAPHIC_GetPairCount(const u16 *p);

unsigned short NAMEIN_GRAPHIC_GetPairEntry(char *base, int i, int j);

int NAMEIN_GRAPHIC_NextPairChar(char *p, const unsigned short *key, unsigned short *out);

u32 NAMEIN_GRAPHIC_IsNameCharValid(u16 *s, u32 x);

extern const char d_021F5798[];
extern const char str_ja_021F55D8[];

void *NAMEIN_GRAPHIC_LoadArcMember(u32 a, u16 b)
{
    return ARC_UTIL_LoadMember(0x77, a, 0, b);
}

void NAMEIN_GRAPHIC_FreeMember(void *p) { GFL_HEAP_Free(p); }

/*
 * evidence: caller consumes 021F4D20 r0; full forwarder leaves 0204A1BC allocation result live despite own void declaration.
 */
void **NAMEIN_GRAPHIC_CreateMembers(u16 heap)
{
    void **p;
    int i = 0;
    p = GFL_HEAP_Alloc(heap, 5 * sizeof(void *), 0, PM_LANG_JA(d_021F5798, str_ja_021F55D8), PM_SRC_LINE(147, 146));
    MI_CpuFill8(p, 0, 5 * sizeof(void *));
    for (; i < 5; i++)
        p[i] = NAMEIN_GRAPHIC_LoadArcMember(i, heap);
    return p;
}

void NAMEIN_GRAPHIC_DeleteMembers(void **p)
{
    int i;

    for (i = 0; i < 5; i++) {
        NAMEIN_GRAPHIC_FreeMember(p[i]);
    }
    GFL_HEAP_Free(p);
}

void *NAMEIN_GRAPHIC_GetWord(void *const *p, u32 i) { return p[i]; }

u16 NAMEIN_GRAPHIC_GetGridWidth(const u16 *p) { return *p; }

u16 NAMEIN_GRAPHIC_GetGridHeight(const u16 *p) { return p[1]; }

u32 NAMEIN_GRAPHIC_GetGridCell(u8 *p, u16 a, u16 b)
{
    return *(u16 *)(p + ((a + b * NAMEIN_GRAPHIC_GetGridWidth((const u16 *)p)) << 1) + 4);
}

void *NAMEIN_GRAPHIC_LoadCharMember(int a, u16 b)
{
    return ARC_UTIL_LoadMember(0x77, a + 5, 0, b);
}

void NAMEIN_GRAPHIC_FreeHandle(void *p) { GFL_HEAP_Free(p); }

u16 NAMEIN_GRAPHIC_GetTableCount(const u16 *p) { return *p; }

void NAMEIN_GRAPHIC_CopyTableEntries(const char *p,int i,u16 *dst,u32 n,u8 *count) {WORDSET_CopyString((const u16 *)(p+2+i*24),dst,n);if(count){*count=0;while(*count<3 && dst[*count]!=0x3000) ++*count;}}

int NAMEIN_GRAPHIC_PickTable8(const char *p, int idx, unsigned short *tab, int val, unsigned char *out)
{
    unsigned char i;

    WORDSET_CopyString((const u16 *)(p + 8 + 0x18 * idx), tab, val);
    i = 0;
    while (i < 3 && tab[i] != 0x3000) {
        i++;
    }
    if (out != 0) {
        *out = (unsigned char)i;
    }
    return i != 0;
}

int NAMEIN_GRAPHIC_PickTableE(const char *p, int idx, unsigned short *tab, int val, unsigned char *out)
{
    unsigned char i;

    WORDSET_CopyString((const u16 *)(p + 0xe + 0x18 * idx), tab, val);
    i = 0;
    while (i < 3 && tab[i] != 0x3000) {
        i++;
    }
    if (out != 0) {
        *out = (unsigned char)i;
    }
    return i != 0;
}

int NAMEIN_GRAPHIC_PickTable14(char *p, int index, unsigned short *table, unsigned n, unsigned char *out)
{
    unsigned char i;
    WORDSET_CopyString((const unsigned short *)(p + 0x14 + 0x18 * index), table, n);
    i = 0;
    while (i < 3 && table[i] != 0x3000) i++;
    if (out != 0) *out = i;
    return i != 0;
}

u16 NAMEIN_GRAPHIC_FindTableIndex(const char *p,const u16 *b) {int n=NAMEIN_GRAPHIC_GetTableCount((const u16 *)p);int i;for(i=0;i<n;i++){if(NAMEIN_GRAPHIC_CompareEntry((const u16 *)(p+2+i*24),b))return i;}return 65535;}

int NAMEIN_GRAPHIC_CompareEntry(const unsigned short *a, const unsigned short *b)
{
    unsigned short sentinel = STRBUF_GetEosChar();
    int i;
    for (i = 0; i < 3; i++, a++, b++) {
        if (*a == 0x3000 && *b == sentinel) return 1;
        if (*a != *b) return 0;
        if (*b == sentinel) return 0;
    }
    return 1;
}

void *NAMEIN_GRAPHIC_LoadPairMember(u16 a)
{
    return ARC_UTIL_LoadMember(0x77, 8, 0, a);
}

void NAMEIN_GRAPHIC_FreePairMember(void *p) {GFL_HEAP_Free(p);}

int NAMEIN_GRAPHIC_GetPairCount(const u16 *p) {return *p;}

unsigned short NAMEIN_GRAPHIC_GetPairEntry(char *base, int i, int j)
{
    return *(unsigned short *)(base + i * 6 + 2 + j * 2);
}

int NAMEIN_GRAPHIC_NextPairChar(char *p, const unsigned short *key, unsigned short *out)
{
    int i, j;
    if (*key == 0x3000) return 0;
    for (i = 0; i < NAMEIN_GRAPHIC_GetPairCount((const u16 *)p); i++) {
        for (j = 0; j < 3; j++) {
            if (*key == NAMEIN_GRAPHIC_GetPairEntry(p, (unsigned short)i, (unsigned short)j)) {
                p += i * 6;
                do {
                    j = (j + 1) % 3;
                    *out = *(unsigned short *)(p + 2 + j * 2);
                } while (*out == 0x3000);
                return 1;
            }
        }
    }
    return 0;
}

/*
 * note (2026-10-05, wD4 lane09): EXACT. `j = 0;` before `p = bufs[k];` at the k-loop top, declaration
 *   order bufs, ret, h, j, idx, k, v, t, and NAMEIN_GRAPHIC_GetGridCell declared with u16 parameters (as its other
 *   callers do) so the call passes m and j uncast; the conversion temp then takes sp+0x20, not sp+0.
 */
u32 NAMEIN_GRAPHIC_IsNameCharValid(u16 *s, u32 x)
{
    u8 *bufs[4];
    u32 ret;
    u8 *h;
    int j, idx, k;
    u32 v;
    int t;
    int i, m;
    u32 found;
    u8 *p;
    v = (x & 0x7FFF) | 0x8000;
    for (i = 0; i < 4; i++) bufs[i] = (u8 *)NAMEIN_GRAPHIC_LoadArcMember(i, (u16)v);
    h = (u8 *)NAMEIN_GRAPHIC_LoadPairMember(v & 0xFFFF);
    ret = 1;
    idx = 0;
    while (s[idx] != STRBUF_GetEosChar()) {
        found = 0;
        for (k = 0; (u32)k < 4; k++) {
            j = 0;
            p = bufs[k];
            for (; j < (int)NAMEIN_GRAPHIC_GetGridHeight((const u16 *)p) && found == 0; j++) {
                for (m = 0; m < (int)NAMEIN_GRAPHIC_GetGridWidth((const u16 *)p) && found == 0; m++) {
                    if (s[idx] == NAMEIN_GRAPHIC_GetGridCell(p, m, j)) found = 1;
                }
            }
        }
        for (t = 0; t < NAMEIN_GRAPHIC_GetPairCount((const u16 *)h); t++) {
            for (m = 0; m < 3; m++) {
                if (s[idx] == NAMEIN_GRAPHIC_GetPairEntry((char *)h, (u16)t, (u16)m)) found = 1;
            }
        }
        if (found == 0) {
            ret = 0;
            break;
        }
        idx++;
    }
    NAMEIN_GRAPHIC_FreePairMember(h);
    for (i = 0; i < 4; i++) NAMEIN_GRAPHIC_FreeMember(bufs[i]);
    return ret;
}
