/*
 * file:     cursor_move.c
 * unit:     yes
 * function: CURSOR_MOVE_GetTableValue, CURSOR_MOVE_GetTableGroup, CURSOR_MOVE_GetTableKind, CURSOR_MOVE_FindTableGroupIndex, CURSOR_MOVE_Create, CURSOR_MOVE_Delete, CURSOR_MOVE_EnableInput, CURSOR_MOVE_SetMode, CURSOR_MOVE_PollInput, CURSOR_MOVE_PollRepeatInput, CURSOR_MOVE_PollTouch, CURSOR_MOVE_GetNeighbour, CURSOR_MOVE_StartInput, CURSOR_MOVE_HandlePendingInput, CURSOR_MOVE_MoveCursor, CURSOR_MOVE_GetCurrent, CURSOR_MOVE_SetCurrent, CURSOR_MOVE_GetState, CURSOR_MOVE_SetState, CURSOR_MOVE_ClearSkipBit, CURSOR_MOVE_SetSkipBit, CURSOR_MOVE_GetEntry, CURSOR_MOVE_IsWrapNeighbour, CURSOR_MOVE_TestSkipBit, CURSOR_MOVE_CreateVecSet, CURSOR_MOVE_DeleteVecSet, GAME_COMM_Update
 * address:  0x02025C74
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   gCursorMoveTable  0x0209FB18  data
 *   sub_02030734  0x02030734  arm
 *   str_020A74A0  0x020A74A0  data
 *   GFL_HEAP_FreeMemory  0x02030164  arm
 *   CURSOR_MOVE_PollTouch  0x02025EA4  thumb
 *   CURSOR_MOVE_HandlePendingInput  0x02025FC8  thumb
 *   CURSOR_MOVE_GetNeighbour  0x02025F60  thumb
 *   CURSOR_MOVE_MoveCursor  0x02026010  thumb
 *   KEY_GetTrg  0x020362DC  arm
 *   func_020355D8  0x020355D8  arm
 *   KEY_GetRepeat  0x0203633C  arm
 *   TOUCHPANEL_HitTrg  0x02035C08  arm
 *   CURSOR_MOVE_TestSkipBit  0x020261C4  thumb
 *   gCursorMoveTouchTag  0x0209FB58  data
 *   UI_SetInputMode  0x020355D8  arm
 *   func_02030734   0x02030734  arm
 *   GAME_DATA_GetMyStatus   0x02012944  thumb
 *   STRBUF_Create   0x020457B0  arm
 *   func_02008500   0x02008500  thumb
 *   g_020A74B0      0x020A74B0  data
 *   STRBUF_Delete  0x02045808  arm
 *   sub_020307B0  0x020307B0  arm
 *   GAME_COMM_KindTable     0x0209FB5C  data
 *   GAME_COMM_SetSeqState  0x02026490  thumb
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

/* One row of the 16-entry table at gCursorMoveTable. */
struct CursorTableRow {
    u16 value;
    u8 kind;
    u8 group;
};

/* One selectable slot: neighbour slot per direction, then a four byte tag. */
struct CursorEntry {
    u32 reserved00;
    u8 next[4];
    u8 tag[4];
};

typedef void (*CursorCb)(u32 ctx, u8 cur, int prev);

struct CursorVtbl {
    CursorCb onStart;
    CursorCb onCancel;
    CursorCb onMove;
    CursorCb onCommit;
};

struct Cursor {
    struct CursorEntry *entries;
    u32 state;
    u32 mode;
    u8 inputEnabled;
    u8 cur;
    u8 prev;
    u8 saved;
    u32 skipBitmap[2];
    struct CursorVtbl *vt;
    u32 ctx;
};

struct VecSetItem {
    u32 reserved00;
    void *buf1;
    void *buf2;
};

struct VecSet {
    void *owner;
    u8 reserved04[0x38];
    struct VecSetItem items[6];
};

struct U16Vec;

struct CursorCommSeq
{
  u32 frameCount;
  u8 state;
  u8 changed;
  u8 reserved06;
  u8 reserved07;
};

struct CursorComm
{
  u32 reserved00;
  u8 exitRequest : 1;
  u8 notifyFlag : 1;
  u8 exitPending : 1;
  u8 reserved3 : 5;
  u8 kind;
  u8 lastKind;
  u8 reserved07;
  u32 counter;
  struct CursorCommSeq seq;
  u32 param;
  u32 work;
  u32 exitArg;
  void (*exitFunc)(u32, u32);
};

struct CursorCommKindFuncs
{
  u32 (*start)(struct CursorCommSeq *, u32);
  u32 (*wait)(struct CursorCommSeq *, u32, u32);
  void (*run)(struct CursorCommSeq *, u32, u32);
  u32 (*stop)(struct CursorCommSeq *, u32, u32);
  u32 (*end)(struct CursorCommSeq *, u32, u32);
  u32 reserved14;
  u32 reserved18;
};

/* the finish arm clears its fields through an enum-typed zero */
typedef enum { Z0 } E;

extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 GFL_HEAP_FreeMemory(void *p);
extern void UI_SetInputMode(u8 v);
extern u32 KEY_GetTrg(void);
extern void func_020355D8(u8 v);
extern unsigned int KEY_GetRepeat(void);
extern int TOUCHPANEL_HitTrg(const void *key);
extern u8 *GAME_DATA_GetMyStatus(void *a0);
extern struct U16Vec *STRBUF_Create(u32 a0, u32 a1);
extern void func_02008500(void *a0, void *a1);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32 sub_020307B0(void *p);
extern void GAME_COMM_SetSeqState(void *obj, u32 value);
extern struct CursorTableRow gCursorMoveTable[];
extern const char str_020A74A0[];
extern const u8 gCursorMoveTouchTag[4];
extern u32 g_020A74B0[];
extern struct CursorCommKindFuncs GAME_COMM_KindTable[];

u32 CURSOR_MOVE_GetTableValue(u32 x);
u32 CURSOR_MOVE_GetTableGroup(u32 x);
u32 CURSOR_MOVE_GetTableKind(u32 x);
u32 CURSOR_MOVE_FindTableGroupIndex(u32 v);
struct Cursor *CURSOR_MOVE_Create(struct CursorEntry *entries, struct CursorVtbl *vt, u32 ctx, u32 state, u8 start, u16 heapId);
u32 CURSOR_MOVE_Delete(void *a0);
void CURSOR_MOVE_EnableInput(struct Cursor *obj);
void CURSOR_MOVE_SetMode(struct Cursor *obj);
int CURSOR_MOVE_PollInput(struct Cursor *obj);
int CURSOR_MOVE_PollRepeatInput(struct Cursor *obj);
int CURSOR_MOVE_PollTouch(struct Cursor *obj, int *out);
u32 CURSOR_MOVE_GetNeighbour(const struct CursorEntry *entries, u32 idx, u32 type);
int CURSOR_MOVE_StartInput(struct Cursor *obj);
int CURSOR_MOVE_HandlePendingInput(struct Cursor *obj);
int CURSOR_MOVE_MoveCursor(struct Cursor *obj, u32 dir, int sel);
u8 CURSOR_MOVE_GetCurrent(struct Cursor *obj);
void CURSOR_MOVE_SetCurrent(struct Cursor *obj, u8 sel);
u32 CURSOR_MOVE_GetState(struct Cursor *obj);
void CURSOR_MOVE_SetState(struct Cursor *obj, u32 state);
void CURSOR_MOVE_ClearSkipBit(struct Cursor *obj, u32 idx);
void CURSOR_MOVE_SetSkipBit(struct Cursor *obj, u32 idx);
struct CursorEntry *CURSOR_MOVE_GetEntry(struct Cursor *obj, u32 idx);
int CURSOR_MOVE_IsWrapNeighbour(const struct CursorEntry *entry, u32 type);
int CURSOR_MOVE_TestSkipBit(const u32 *bitmap, u32 bit);
struct VecSet *CURSOR_MOVE_CreateVecSet(u32 a0, void *a1);
void CURSOR_MOVE_DeleteVecSet(struct VecSet *obj);
void GAME_COMM_Update(struct CursorComm *p);


/*
 * Halfword accessor over the 0x10-entry table of 4-byte records at
 * 0x0209FB18 (u16, u8, u8; CURSOR_MOVE_GetTableKind reads the u8 at +2, CURSOR_MOVE_GetTableGroup
 * the one at +3); out of range returns 0xB.  Seeded from ov019 0x0217AE76
 * and ov021 0x021CFCD6.
 *
 * Addresses are Black-image addresses.
 */
u32 CURSOR_MOVE_GetTableValue(u32 x)
{
    if (x >= 0x10u)
        return 0xB;
    return gCursorMoveTable[x].value;
}


/*
 * Unlabelled Thumb leaf in the ARM9 module: byte accessor over a 0x10-entry
 * table of 4-byte records.
 *
 * Addresses are Black-image addresses.
 */
u32 CURSOR_MOVE_GetTableGroup(u32 x)
{
    if (x >= 0x10u)
        return 2;
    return gCursorMoveTable[x].group;
}


/*
 * Two more leaves over the 0x10-entry table of 4-byte records at 0x0209FB18
 * (see CURSOR_MOVE_GetTableValue and CURSOR_MOVE_GetTableGroup): the byte at +2 of entry x (2 when
 * out of range), and the index of the first entry whose byte at +3 equals v
 * (0 when none does).  Seeded from ov111 0x021C6216 and ov116 0x021D6AAC.
 *
 * Addresses are Black-image addresses.
 */
u32 CURSOR_MOVE_GetTableKind(u32 x)
{
    if (x >= 0x10u)
        return 2;
    return gCursorMoveTable[x].kind;
}


u32 CURSOR_MOVE_FindTableGroupIndex(u32 v)
{
    u32 i;

    for (i = 0; i < 0x10; i++) {
        if (v == gCursorMoveTable[i].group)
            return i;
    }
    return 0;
}


struct Cursor *CURSOR_MOVE_Create(struct CursorEntry *entries, struct CursorVtbl *vt, u32 ctx, u32 state, u8 start, u16 heapId)
{
    struct Cursor *p = (struct Cursor *)sub_02030734(heapId, 0x20, 0, str_020A74A0, 0x6a);

    p->entries = entries;
    p->vt = vt;
    p->ctx = ctx;
    p->inputEnabled = 0;
    p->state = state;
    p->mode = 0;
    p->cur = start;
    p->prev = 0xff;
    p->saved = 0xff;
    p->skipBitmap[0] = -1;
    p->skipBitmap[1] = -1;

    return p;
}


/*
 * Unlabelled Thumb leaf: a bare tail call to GFL_HEAP_FreeMemory with no arguments.
 * `ldr r3,[pc,#0]; bx r3` (the pool word names 0x02030164).  Disasm.py did
 * not label it because it has no prologue; the live bytes decode as Thumb.
 */
u32 CURSOR_MOVE_Delete(void *a0)
{
    return GFL_HEAP_FreeMemory(a0);
}


void CURSOR_MOVE_EnableInput(struct Cursor *obj)
{
    obj->inputEnabled = 1;
}


void CURSOR_MOVE_SetMode(struct Cursor *obj)
{
    obj->mode = 1;
}


/*
 * field_sound_system.c.  The primary-pad poll: with no pending selection, read the four direction bits of the button word and hand the matching entry to CURSOR_MOVE_MoveCursor; B answers the current slot and A answers -2.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CURSOR_MOVE_PollInput.c \
 *       --func CURSOR_MOVE_PollInput --addr 0x02025D2C --cc 1.1p1 --thumb
 */
int CURSOR_MOVE_PollInput(struct Cursor *obj)
{
    int dir;
    int res;
    u32 sel;

    if (CURSOR_MOVE_PollTouch(obj, &res) == 1) {
        return res;
    }
    if (obj->state == 0 && obj->inputEnabled == 1) {
        return CURSOR_MOVE_HandlePendingInput(obj);
    }

    if (KEY_GetTrg() & 0x40) {
        sel = CURSOR_MOVE_GetNeighbour(obj->entries, obj->cur, 0);
        dir = 0;
    } else if (KEY_GetTrg() & 0x80) {
        sel = CURSOR_MOVE_GetNeighbour(obj->entries, obj->cur, 1);
        dir = 1;
    } else if (KEY_GetTrg() & 0x20) {
        sel = CURSOR_MOVE_GetNeighbour(obj->entries, obj->cur, 2);
        dir = 2;
    } else if (KEY_GetTrg() & 0x10) {
        sel = CURSOR_MOVE_GetNeighbour(obj->entries, obj->cur, 3);
        dir = 3;
    } else {
        sel = 0xff;
    }

    if (sel != 0xff) {
        return CURSOR_MOVE_MoveCursor(obj, dir, sel);
    }
    if (KEY_GetTrg() & 1) {
        func_020355D8(0);
        return obj->cur;
    }
    if (KEY_GetTrg() & 2) {
        dir = 0;
        func_020355D8(0);
        return dir - 2;
    }
    return -1;
}


/*
 * field_sound_system.c.  The secondary-pad twin of CURSOR_MOVE_PollInput: identical shape, but the four direction bits come from KEY_GetRepeat while the two action bits still come from KEY_GetTrg.
 *
 * CURSOR_MOVE_MoveCursor takes three arguments; the third is the slot value
 * CURSOR_MOVE_GetNeighbour returned, which reads at the call site as a leftover r2 but
 * is a real argument -- without it the `adds r2, r0, #0` after the call is
 * dead-code eliminated and the function comes out two bytes short.
 */
int CURSOR_MOVE_PollRepeatInput(struct Cursor *obj)
{
    u32 sel;
    u32 dir;
    int res;

    if (CURSOR_MOVE_PollTouch(obj, &res) == 1) {
        return res;
    }
    if (obj->state == 0 && obj->inputEnabled == 1) {
        return CURSOR_MOVE_HandlePendingInput(obj);
    }

    if (KEY_GetRepeat() & 0x40) {
        sel = CURSOR_MOVE_GetNeighbour(obj->entries, obj->cur, 0);
        dir = 0;
    } else if (KEY_GetRepeat() & 0x80) {
        sel = CURSOR_MOVE_GetNeighbour(obj->entries, obj->cur, 1);
        dir = 1;
    } else if (KEY_GetRepeat() & 0x20) {
        sel = CURSOR_MOVE_GetNeighbour(obj->entries, obj->cur, 2);
        dir = 2;
    } else if (KEY_GetRepeat() & 0x10) {
        sel = CURSOR_MOVE_GetNeighbour(obj->entries, obj->cur, 3);
        dir = 3;
    } else {
        sel = 0xff;
    }

    if (sel != 0xff) {
        return CURSOR_MOVE_MoveCursor(obj, dir, sel);
    }
    if (KEY_GetTrg() & 1) {
        func_020355D8(0);
        return obj->cur;
    }
    if (KEY_GetTrg() & 2) {
        dir = 0;
        func_020355D8(0);
        return dir - 2;
    }
    return -1;
}


/*
 * Scan the entry table hanging off the object for a live record: each
 * entry's tag word is copied into the low half of a 8-byte stack scratch
 * whose high half is preloaded from the four-byte template gCursorMoveTouchTag, then
 * handed to TOUCHPANEL_HitTrg.  A hit that also passes the bitmap test commits
 * the entry: the previous slot id is shifted to prev, the new index becomes
 * cur, an in-flight request (state == 1 with inputEnabled == 1) is cancelled
 * through the vtable slot 4 before the normal slot C notification, and the
 * caller's out word receives the index.
 */
/*
 * field_sound_system.c.  Scan the entry table hanging off the object for a
 * live record: each 12-byte entry's tag word (bytes 8..11) is copied into
 * the low half of a 8-byte stack scratch whose high half is preloaded from
 * the four-byte template gCursorMoveTouchTag, then handed to TOUCHPANEL_HitTrg.  A hit
 * that also passes the bitmap test at +0x10 commits the entry: the previous
 * slot id is shifted to +0xe, the new index becomes +0xd, an in-flight
 * request (state == 1 with inputEnabled == 1) is cancelled through the record's
 * vtable slot +4 before the normal slot +0xc notification, and the caller's
 * out word receives the index.
 *
 * occurrence of the address anywhere in the image (arm9 and overlays), so the
 * only witness for the ABS32 site lies inside this function's own extent.
 * No evidence class applies -- `literal` needs the word at a different
 * address, `label` and `matched` need code -- so the function caps at MATCH
 * regardless of how the C is spelled.  Unstick it by decompiling any other
 * reader of 0x0209FB58, which would supply a second pool word.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/CURSOR_MOVE_PollTouch.c \
 *       --func CURSOR_MOVE_PollTouch --addr 0x02025EA4 --cc 1.1p1 --thumb
 */
int CURSOR_MOVE_PollTouch(struct Cursor *obj, int *out)
{
    u8 key[8];
    u16 i;
    int res;
    u32 *bitmap;
    struct CursorEntry *e;

    key[4] = gCursorMoveTouchTag[0];
    key[5] = gCursorMoveTouchTag[1];
    key[6] = gCursorMoveTouchTag[2];
    key[7] = gCursorMoveTouchTag[3];
    res = 0;
    i = res;
    bitmap = obj->skipBitmap;
    *out = res - 1;

    while (1) {
        e = (struct CursorEntry *)((u8 *)obj->entries + i * 12);
        if (e->tag[0] == 0xff) {
            break;
        }
        key[0] = ((volatile struct CursorEntry *)e)->tag[0];
        key[1] = e->tag[1];
        key[2] = e->tag[2];
        key[3] = e->tag[3];
        if (TOUCHPANEL_HitTrg(key) != -1) {
            res = 1;
            if (CURSOR_MOVE_TestSkipBit(bitmap, i) == 1) {
                obj->prev = obj->cur;
                obj->cur = (u8)i;
                if (obj->state == 1 && obj->inputEnabled == 1) {
                    obj->state = 0;
                    obj->vt->onCancel(obj->ctx, obj->cur, obj->prev);
                }
                obj->vt->onCommit(obj->ctx, obj->cur, obj->prev);
                obj->prev = 0xff;
                obj->saved = 0xff;
                *out = i;
                func_020355D8(1);
                break;
            }
        }
        i = i + 1;
    }
    return res;
}


u32 CURSOR_MOVE_GetNeighbour(const struct CursorEntry *entries, u32 idx, u32 type)
{
    switch (type) {
    case 0:
        idx = entries[idx].next[0];
        break;
    case 1:
        idx = entries[idx].next[1];
        break;
    case 2:
        idx = entries[idx].next[2];
        break;
    case 3:
        idx = entries[idx].next[3];
        break;
    }

    return idx;
}


int CURSOR_MOVE_StartInput(struct Cursor *obj)
{
    int one = 1;

    UI_SetInputMode(0);
    obj->state = one;
    obj->prev = 0xff;
    obj->saved = 0xff;
    obj->vt->onStart(obj->ctx, obj->cur, obj->prev);

    return one - 5;
}


/*
 * Poll the pending-interrupt word and answer with the slot a matching mask
 * selects: mode 1 (a0[8] == 1) tests 0xf3, the other path tests 0xf1 and
 * then bit 1; a hit runs CURSOR_MOVE_StartInput and returns its value, a miss in the
 * bit-1 case answers -2 and a miss anywhere else answers -1.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CURSOR_MOVE_HandlePendingInput.c \
 *       --func CURSOR_MOVE_HandlePendingInput --addr 0x02025FC8 --cc 1.1p1 --thumb
 */
int CURSOR_MOVE_HandlePendingInput(struct Cursor *obj)
{
    if (obj->mode == 1) {
        if (KEY_GetTrg() & 0xf3) {
            return CURSOR_MOVE_StartInput(obj);
        }
    } else if (KEY_GetTrg() & 0xf1) {
        return CURSOR_MOVE_StartInput(obj);
    } else if (KEY_GetTrg() & 2) {
        CURSOR_MOVE_StartInput(obj);
        return -2;
    }
    return -1;
}


/*
 * field_sound_system.c.  Moves the cursor from the current entry to the
 * one CURSOR_MOVE_GetNeighbour names for `dir`, skipping entries whose bit is clear
 * in the object's 32-bit-word skip bitmap, then notifies the owner.
 */
int CURSOR_MOVE_MoveCursor(struct Cursor *obj, u32 dir, int sel)
{
    int direct;
    u32 n;

    func_020355D8(0);

    if (sel & 0x80) {
        if (obj->saved != 0xff) {
            sel = obj->saved;
        } else {
            sel ^= 0x80;
        }
    }

    direct = 1;
loop:
    if ((obj->skipBitmap[(u32)sel >> 5] & (1 << (sel % 32))) == 0) {
        direct = 0;
        n = (u8)(CURSOR_MOVE_GetNeighbour(obj->entries, sel, dir) & 0x7f);
        if (n == (u32)sel || n == obj->cur) {
            sel = obj->cur;
        } else {
            sel = n;
            goto loop;
        }
    }

    if (obj->cur != sel) {
        if (CURSOR_MOVE_IsWrapNeighbour(&obj->entries[sel], dir) == 1 && direct) {
            obj->saved = obj->cur;
        } else {
            obj->saved = 0xff;
        }

        {
            u8 prev = obj->cur;
            struct CursorVtbl *vt = obj->vt;
            u32 ctx = obj->ctx;

            obj->cur = (u8)sel;
            obj->prev = prev;
            vt->onMove(ctx, obj->cur, obj->prev);
        }
        return -3;
    }

    if (dir == 0) {
        return -8;
    }
    if (dir == 1) {
        return -7;
    }
    if (dir == 2) {
        return -6;
    }
    if (dir == 3) {
        return -5;
    }
    return -1;
}


/*
 * field_sound_system.c accessors following src/matched/CURSOR_MOVE_MoveCursor.c:
 * read the current cursor entry, set it (clearing the two trailing
 * cached indices to 0xff), and read the state word.  All leaves; calls nothing.
 */
u8 CURSOR_MOVE_GetCurrent(struct Cursor *obj)
{
    return obj->cur;
}


void CURSOR_MOVE_SetCurrent(struct Cursor *obj, u8 sel)
{
    obj->cur = sel;
    obj->prev = 0xff;
    obj->saved = 0xff;
}


u32 CURSOR_MOVE_GetState(struct Cursor *obj)
{
    return obj->state;
}


void CURSOR_MOVE_SetState(struct Cursor *obj, u32 state)
{
    obj->state = state;
    if (state == 1) {
        obj->prev = 0xff;
        obj->saved = 0xff;
        obj->vt->onStart(obj->ctx, obj->cur, -1);
    } else {
        obj->vt->onCancel(obj->ctx, obj->cur, -1);
    }
}


/*
 * field_sound_system.c leaves after src/matched/sub_020260F4.c, on the
 * same object as src/matched/unit_020260E0.c: clear a bit in the flag
 * words at +0x10, set it, and address an entry of the 12-byte table.
 * The clear spells ~m as m ^ 0xFFFFFFFF (the compiler derives -1 from the
 * live 0x1f with subs #0x20); the set is an xor guarded by the test.
 * Seeded from ov170 (0x021DF6AE, 0x021EA0FE, 0x021EA892) and ov069/ov136.
 */
void CURSOR_MOVE_ClearSkipBit(struct Cursor *obj, u32 idx)
{
    u32 w = idx / 32;
    u32 b = idx % 32;
    if (obj->skipBitmap[w] & (1 << b)) {
        obj->skipBitmap[w] &= (1 << b) ^ 0xFFFFFFFF;
    }
}


void CURSOR_MOVE_SetSkipBit(struct Cursor *obj, u32 idx)
{
    u32 w = idx / 32;
    u32 b = idx % 32;
    if ((obj->skipBitmap[w] & (1 << b)) == 0) {
        obj->skipBitmap[w] ^= (1 << b);
    }
}


struct CursorEntry *CURSOR_MOVE_GetEntry(struct Cursor *obj, u32 idx)
{
    return &obj->entries[idx];
}


int CURSOR_MOVE_IsWrapNeighbour(const struct CursorEntry *entry, u32 type)
{
    switch (type) {
    case 0:
        if (entry->next[1] & 0x80) {
            return 1;
        }
        break;
    case 1:
        if (entry->next[0] & 0x80) {
            return 1;
        }
        break;
    case 2:
        if (entry->next[3] & 0x80) {
            return 1;
        }
        break;
    case 3:
        if (entry->next[2] & 0x80) {
            return 1;
        }
        break;
    }
    return 0;
}


int CURSOR_MOVE_TestSkipBit(const u32 *bitmap, u32 bit)
{
    u32 mask = 1 << (bit & 0x1f);
    int res = 1;

    if ((bitmap[bit >> 5] & mask) == 0) {
        res = 0;
    }
    return res;
}


/*
 * Allocate the 0x88-byte sprite for a1 (tag 0xe0), keep a1 as its first word,
 * then attach six sub-buffers: each starts at +0x3c with a 0xc stride, gets
 * two 8-byte allocations out of the a0 heap and registers both with the
 * resource handle GAME_DATA_GetMyStatus returned for a1.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CURSOR_MOVE_CreateVecSet.c \
 *       --func CURSOR_MOVE_CreateVecSet --addr 0x020261E4 --cc 1.1p1 --thumb
 */
struct VecSet *CURSOR_MOVE_CreateVecSet(u32 a0, void *a1)
{
    int i;
    struct VecSet *p;
    struct VecSetItem *base;
    struct VecSetItem *e;
    u8 *q;

    p = (struct VecSet *)sub_02030734(a0, 0x88, 1, (const char *)g_020A74B0, 0xe0);
    p->owner = a1;
    q = GAME_DATA_GetMyStatus(a1);
    base = p->items;
    for (i = 0; i < 6; i++) {
        e = base + i;
        e->buf1 = STRBUF_Create(8, a0);
        e->buf2 = STRBUF_Create(8, a0);
        func_02008500(q, e->buf1);
        func_02008500(q, e->buf2);
    }
    return p;
}


void CURSOR_MOVE_DeleteVecSet(struct VecSet *obj)
{
    struct VecSetItem *items = obj->items;
    int i;

    for (i = 0; i < 6; i++) {
        STRBUF_Delete(items[i].buf1);
        STRBUF_Delete(items[i].buf2);
    }
    sub_020307B0(obj);
}

/*
 * game_comm.c: the per-frame request state machine.  The request kind
 * (+5) selects a 0x1C-byte record of callbacks in the table at 0x0209FB5C
 * (GAME_COMM_CallHandler and GAME_COMM_CallKindNotify read its words at +0x14 and +0x18); the
 * state byte of the 8-byte sub-object at +0xC is the dense switch.
 *
 * Closed 2026-09-24 (wave 21, lane E) after the DIFF 10 recorded in
 * docs/notes/pkt_0202627C.c.txt.  The lever is the finish arm's zero typed
 * as an enum (`E z = Z0` assigned first, then cb, a, b read in that order):
 * with -enum int an enum value is not constant-propagated the way a u32
 * zero is, so the zero keeps its own web (r2, shared with the bics mask)
 * and the callback takes r5 as in the image.  A u32 zero in the same
 * position is 13 out; see
 * docs/idioms/an-enum-type-keeps-values-out-of-constant-folding.md.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/GAME_COMM_Update.c \
 *       --func GAME_COMM_Update --addr 0x0202627C --cc 1.1p1 --thumb
 */
void GAME_COMM_Update(struct CursorComm *p)
{
  struct CursorCommSeq *sub;
  struct CursorCommKindFuncs *rec;
  if ((p == 0) || (p->kind == 0))
    return;
  sub = &p->seq;
  rec = &GAME_COMM_KindTable[p->kind];
  if (sub->changed == 1)
  {
    sub->frameCount = 0;
    sub->changed = 0;
  }
  switch (sub->state)
  {
    case 0:
      if (rec->start != 0)
      p->work = rec->start(sub, p->param);
      p->lastKind = p->kind;
      p->counter = 0;
      GAME_COMM_SetSeqState(sub, 1);
      break;

    case 1:
      if ((rec->wait == 0) || (rec->wait(sub, p->param, p->work) == 1))
      GAME_COMM_SetSeqState(sub, 2);
      break;

    case 2:
      if (p->exitRequest == 1)
    {
      p->exitRequest = 0;
      GAME_COMM_SetSeqState(&p->seq, 3);
      break;
    }
      rec->run(sub, p->param, p->work);
      break;

    case 3:
      if (rec->stop != 0)
    {
      if (rec->stop(sub, p->param, p->work) == 1)
        GAME_COMM_SetSeqState(sub, 4);
    }
    else
    {
      GAME_COMM_SetSeqState(sub, 4);
    }
      break;

    case 4:
      if ((rec->end != 0) && (rec->end(sub, p->param, p->work) != 1))
      break;
      GAME_COMM_SetSeqState(sub, 5);

    case 5:
    {
      void (*cb)(u32, u32);
      u32 a;
      u32 b;
      E z;
      z = Z0;
      cb = p->exitFunc;
      a = p->exitArg;
      b = p->notifyFlag;
      p->work = z;
      p->kind = z;
      p->exitFunc = 0;
      p->exitArg = z;
      p->notifyFlag = 0;
      if (cb != 0)
        cb(a, b);
      break;
    }

  }

}
