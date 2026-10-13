/*
 * function: func_0217B984
 * address: 0x0217B984
 * packet: pkt_ov176_0217B984
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Note 2026-10-04 (wD2 lane12): byte-correct. Only unresolved relocation: func_0200EA08 (witness). Filed src/matched/arm9/func_0200EA08.c (EXACT) this wave; it needs a manifest/shard so the witness exists, then this file re-verifies as EXACT with no C change.
 * blocker: 0x0200EA08 Thumb EXACT (scratch one, fixed flags); ARM9 belongs to the integrator.
 *   unsigned char *func_0200EA08(unsigned char *p) { return p; }
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   BATTLE_REC_IsDataExist 0x0200B45C thumb
 *   func_021E58A4 0x021E58A4 thumb ov177
 *   func_0201EC74 0x0201EC74 thumb
 *   func_02045B38 0x02045B38 arm
 *   GF_FONT_Create 0x0201D7EC thumb
 *   func_021E8A3C 0x021E8A3C thumb ov177
 *   func_0217BB58 0x0217BB58 thumb ov176
 *   func_0217E00C 0x0217E00C thumb ov176
 *   func_021E5548 0x021E5548 thumb ov177
 *   func_021E7D20 0x021E7D20 thumb ov177
 *   func_021E7E0C 0x021E7E0C thumb ov177
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   func_0200B358 0x0200B358 thumb
 *   func_0200B1D4 0x0200B1D4 thumb
 *   func_0200E9F4 0x0200E9F4 thumb
 *   func_0200EA08 0x0200EA08 thumb
 *   func_0201A920 0x0201A920 thumb
 *   func_0203516C 0x0203516C arm
 *   d_0217E600 0x0217E600 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned u32;
typedef struct {u32 w[10];} Init;
typedef enum {SIZE0=0} Size;
struct Big;
struct GfFont;
struct MsgBank;
struct Party;
struct Rec160;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082BCC(void *,int,u32);
extern u32 BATTLE_REC_IsDataExist(void);
extern void func_021E58A4(int,int,u32);
extern void *func_0201EC74(u32,u32,u32);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern int *func_021E8A3C(int,int,int);
extern void func_0217BB58(int p, int *state, char *q);
extern void *func_0217E00C(int,int);
extern int func_021E5548(int *);
extern void **func_021E7D20(void *,void *,u32);
extern void func_021E7E0C(void **,int);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *func_0200B358(void *);
extern struct Rec160 *func_0200B1D4(struct Rec160 *arr, u32 index);
extern void *func_0200E9F4(void *);
extern int func_0200EA08(int p);
extern struct Party *func_0201A920(u32 heap);
extern void func_0203516C(int);
extern const char d_0217E600[];
u8 *func_0217B984(Init *src,u32 heap)
{
    int size=0x109;
    u8 *p;
    size=0x1dc;
    p=func_02030734(heap,size,0,d_0217E600,0x109);
    func_02082BCC(p,0,size);
    *(Init *)(p+0x1a0)=*src;
    *(u16 *)(p+0x1c8)=heap;
    *(u32 *)(p+0x1d0)=BATTLE_REC_IsDataExist();
    func_021E58A4(*(int *)(p+0x1b0),1,heap);
    *(void **)(p+0x2c)=func_0201EC74(8,0x40,heap);
    *(void **)(p+0x20)=func_02045B38(0,2,0x3a,heap);
    *(void **)(p+0x24)=func_02045B38(0,2,0xd2,heap);
    *(void **)(p+0x28)=GF_FONT_Create(0x17,3,0,0,heap);
    *(int **)p=func_021E8A3C((int)p,(int)func_0217BB58,heap);
    *(void **)(p+0xc)=func_0217E00C(*(int *)(p+0x1b8),heap);
    *(void ***)(p+0x1c)=func_021E7D20((void *)func_021E5548(*(int **)(p+0x1b4)),*(void **)(p+0x1b0),heap);
    func_021E7E0C(*(void ***)(p+0x1c),0);
    *(void **)(p+0x38)=func_0200B1D4(func_0200B358(GAME_DATA_GetSaveControl(*(void **)(p+0x1b8))),1);
    *(void **)(p+0x34)=(void *)func_0200EA08((int)func_0200E9F4(GAME_DATA_GetSaveControl(*(void **)(p+0x1b8))));
    *(void **)(p+0x30)=func_0201A920(heap);
    if(*(int *)(p+0x1a0)==0)func_0203516C(8);
    return p;
}
