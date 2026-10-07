/*
 * file:     unit_0220BC70_p07.c
 * unit:     yes
 * function: func_0220E7CC, func_0220E7E4, func_0220E82C, func_0220E8B4, func_0220E974
 * address:  0x0220E7CC
 * region:   ov198
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0201BB5C 0x0201BB5C thumb
 *   func_0204B6F4 0x0204B6F4 arm
 *   func_020490F4 0x020490F4 arm
 *   func_020275F8 0x020275F8 thumb
 *   func_02049E74 0x02049E74 arm
 *   func_0204A9D0 0x0204A9D0 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02049238 0x02049238 arm
 *   func_020275EC 0x020275EC thumb
 *   func_02027610 0x02027610 thumb
 *   func_02027604 0x02027604 thumb
 *   func_0204B404 0x0204B404 arm
 *   func_0204B878 0x0204B878 arm
 */
struct Obj;
struct Vec2;
struct Sub0204A9D0;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct {u8 half:3; u8 middle:4; u8 egg:1;} Flags_0220E7E4;

typedef struct {char pad0[8];u16 species;char padA[34];unsigned form;char rest[28];} Record;

typedef struct {u8 low:7;u8 flip:1;} Flags_0220E8B4;

extern void func_0204B3DC(struct Obj *, unsigned int);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern unsigned func_0201BB5C(unsigned,unsigned,unsigned,unsigned);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern u32 func_020275F8(u32 a);
extern void *func_02049E74(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void func_0204A9D0(int,struct Sub0204A9D0 *);
extern u32 func_020307B0(void *p);
extern void func_02049238(void *);
extern u8 func_020275EC(int i);
extern u32 func_02027610(u32 a);
extern u8 func_02027604(u8 i);
extern void func_0204B404(struct Obj *,const struct Vec2 *,u32),func_0204B878(struct Obj *,u32);
void func_0220E7CC(u8 *p, u32 b);
void func_0220E7E4(Record *records);
void func_0220E82C(char *p,void *obj,int index,int which);
void func_0220E8B4(char *p,int first,int index,int which);
void func_0220E974(int mode,u8 *p,const struct Vec2 *q);


/*
 * Addresses are Black-image addresses.
 */
void func_0220E7CC(u8 *p, u32 b)
{
    func_0204B3DC((struct Obj *)p, 1);
    func_0204B404((struct Obj *)p, (const struct Vec2 *)b, 1);
}

void func_0220E7E4(Record *records)
{
    char *p=(char *)records;
    char *flags;
    short i;
    unsigned value;
    i=0;
    flags=p+0x1b;
    for(;i<6;i++) {
        if(records[i].species!=0) {
            value=func_0201BB5C(records[i].species,records[i].form,((Flags_0220E7E4 *)(flags+i*0x4c))->half,((Flags_0220E7E4 *)(flags+i*0x4c))->egg);
            func_0204B6F4(*(void **)(p+i*4+0x1ed8),value,1);
        }
    }
}

/*
 * Verified scratch one: EXACT 12 bytes, Thumb, dsi/1.1p1 -O4,p.
 * typedef unsigned char u8;
 * extern const u8 d_0209FCF8[];
 * unsigned func_020275EC(u8 index){return d_0209FCF8[index];}
 */
void func_0220E82C(char *p,void *obj,int index,int which)
{
    void *owner,*data;
    struct Sub0204A9D0 *out;
    owner=func_020490F4(83,(u16)((*(u16 *)(*(char **)p+16)&0x7fff)|0x8000));
    data=func_02049E74((void *)((unsigned)owner),func_020275F8((u8)which),0,(unsigned)&out,(*(u16 *)(*(char **)p+16)&0x7fff)|0x8000);
    func_0204A9D0(*(unsigned *)(p+index*4+0x24a4),out);
    func_020307B0(data);
    func_02049238(owner);
    func_0204B6F4(obj,(unsigned)func_020275EC((u8)which),1);
}

/*
 * Verified scratch one: EXACT 12 bytes, Thumb, dsi/1.1p1 -O4,p.
 * typedef unsigned char u8;
 * extern const u8 d_0209FCEC[];
 * unsigned func_02027604(u8 index){return d_0209FCEC[index];}
 */
void func_0220E8B4(char *p,int first,int index,int which)
{
    void *owner,*data;
    struct Sub0204A9D0 *out;
    int toggle;
    toggle=((Flags_0220E8B4 *)(p+0x2175))->flip;
    first+=toggle;
    index+=toggle;
    owner=func_020490F4(83,(u16)((*(u16 *)(*(char **)p+16)&0x7fff)|0x8000));
    data=func_02049E74((void *)((unsigned)owner),func_02027610((u8)which),0,(unsigned)&out,(*(u16 *)(*(char **)p+16)&0x7fff)|0x8000);
    func_0204A9D0(*(int *)(p+index*4+0x24a4),out);
    func_020307B0(data);
    func_02049238(owner);
    func_0204B6F4(*(void **)(p+first*4+0x1ebc),(unsigned)func_02027604(which),1);
    ((Flags_0220E8B4 *)(p+0x2175))->flip^=1;
}

void func_0220E974(int mode,u8 *p,const struct Vec2 *q) { if(mode==8)func_0204B404((struct Obj *)p,q,1);else {func_0204B878((struct Obj *)p,mode);func_0220E7CC(p,(u32)q);} }
