/*
 * function: func_021D5110
 * address: 0x021D5110
 * packet: pkt_ov122_021D5110
 * region: ov122
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203CF10 0x0203CF10 arm
 *   func_020457B0 0x020457B0 arm
 *   func_02045994 0x02045994 arm
 *   func_0204B3F4 0x0204B3F4 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_02041B6C 0x02041B6C arm
 *   func_02045808 0x02045808 arm
 *   CLACT_GetActorAnimSeq 0x0204B898 arm
 *   func_0204B878 0x0204B878 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_021D50B4 0x021D50B4 thumb ov122
 *   func_021D50DC 0x021D50DC thumb ov122
 *   FIELD_SOUND_SYSTEM_StartRingtone  0x02028A64  thumb  arm9
 *   COMM_PLAYER_SUPPORT_GetRecordFieldPtr  0x0202E930  thumb  arm9
 */
#include "../include/Obj00208.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct BigObj;
extern u32 func_0201283C(const struct BigObj *p);
extern int func_020107FC(void *);
extern u32 func_0203CF10(u32 a);
struct Cfg;
struct CharBuf;
struct Descriptor;
struct Obj;
struct SoundSys;
struct Strbuf;
struct U16Vec;
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern u16 *COMM_PLAYER_SUPPORT_GetRecordFieldPtr(void *);
extern void func_02045994(struct Strbuf *o, const u16 *src, u32 len);
extern u32 func_0204B3F4(struct Obj *p);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0201C7D0(void *, s16, s16, void *, void *, u16);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_02041B6C(u32 bit);
extern void func_021D50B4(char *p, u32 n);
extern void func_02045808(struct U16Vec *vec);
struct BigObj;
extern unsigned int func_02012A30(const struct BigObj *);
extern void FIELD_SOUND_SYSTEM_StartRingtone(struct SoundSys *sys);
extern void func_02028A70(struct SoundSys *sys);
extern u16 CLACT_GetActorAnimSeq(struct Obj *p);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_021D50DC(char *);
void func_021D5110(char *p)
{
    int index;
    void *record, *text;
    index = func_020107FC((void *)func_0201283C(((struct Obj00208 *)p)->f350));
    if (index != -1) {
        record = (void *)func_0203CF10(index);
        text = func_020457B0(200, ((struct Obj00208 *)p)->fC);
        func_02045994(text, COMM_PLAYER_SUPPORT_GetRecordFieldPtr(record), 8);
        if (!func_0204B3F4(((struct Obj00208 *)p)->f3A0)) {
            func_02045994(((struct Obj00208 *)p)->f58, COMM_PLAYER_SUPPORT_GetRecordFieldPtr(record), 8);
            func_02043B5C(func_02045770(((struct Obj00208 *)p)->f3C), 0);
            func_0201C7D0(func_02045770(((struct Obj00208 *)p)->f3C), 0, 0, ((struct Obj00208 *)p)->f58, ((struct Obj00208 *)p)->f4C, 0x39e3);
            func_02045334(((struct Obj00208 *)p)->f3C);
            func_02045374(((struct Obj00208 *)p)->f3C);
            func_0204B3DC(((struct Obj00208 *)p)->f3A0, 1);
            func_02041B6C(5);
            func_021D50B4(p, index);
        }
        func_02045808(text);
        FIELD_SOUND_SYSTEM_StartRingtone((struct SoundSys *)func_02012A30(((struct Obj00208 *)p)->f350));
        if (CLACT_GetActorAnimSeq(((struct Obj00208 *)p)->f39C) == 15)
            func_0204B878(((struct Obj00208 *)p)->f39C, 16);
        if (CLACT_GetActorAnimSeq(((struct Obj00208 *)p)->f394) == 11) {
            func_0204B92C(((struct Obj00208 *)p)->f394, 1);
            func_0204B878(((struct Obj00208 *)p)->f394, 19);
        }
    } else {
        func_02028A70((struct SoundSys *)func_02012A30(((struct Obj00208 *)p)->f350));
        func_0204B3DC(((struct Obj00208 *)p)->f3A0, 0);
        func_02043B5C(func_02045770(((struct Obj00208 *)p)->f3C), 0);
        func_02045334(((struct Obj00208 *)p)->f3C);
        func_021D50DC(p);
        if (CLACT_GetActorAnimSeq(((struct Obj00208 *)p)->f394) == 19) {
            func_0204B92C(((struct Obj00208 *)p)->f394, 0);
            func_0204B878(((struct Obj00208 *)p)->f394, 11);
        }
        if (CLACT_GetActorAnimSeq(((struct Obj00208 *)p)->f39C) == 16)
            func_0204B878(((struct Obj00208 *)p)->f39C, 15);
    }
}
