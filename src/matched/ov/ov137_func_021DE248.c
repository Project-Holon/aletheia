/*
 * function: func_021DE248
 * address: 0x021DE248
 * packet: pkt_ov137_021DE248
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: Two-byte alignment padding at 0x021DE34E.
 * lever: Struct members avoid cached element addresses; block scopes and expanding the first y argument settle the two spill slots.
 * symbols:
 *   func_02039338 0x02039338 arm
 *   func_021DE388 0x021DE388 thumb ov137
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02008534 0x02008534 thumb
 *   func_020457B0 0x020457B0 arm
 *   func_02008500 0x02008500 thumb
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201F250 0x0201F250 thumb
 *   func_0201C7D0 0x0201C7D0 thumb
 *   func_02045808 0x02045808 arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 */
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef struct { void *current; void *previous; } Entry;
typedef struct { char pad[0x38]; void *font; void *formatter; void *bank; void *names[5]; char pad58[0xe0]; Entry entries[5]; } Context;
typedef unsigned char  u8;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct Sub0200852CObj;
struct U16Vec;
struct WordSet;
extern u16 func_02039338(void);
extern int func_021DE388(void *);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern u16 func_02008534(const struct Sub0200852CObj *obj);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02008500(void *,void *);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_0201C7D0(void *,s16,s16,void *,void *,u16);
extern void func_02045808(struct U16Vec *vec);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32 index);
int func_021DE248(void *window,int unused,u16 color,Context *p) {
    int player;
    void *format;
    u16 value;
    void *text;
    int i;
    u16 ink;
    player=func_02039338();
    if (!func_021DE388(p)) return 0;
    func_02043B5C(func_02045770(window),0);
    for(i=0;i<5;i++) {
      do {
        if (p->entries[i].current) {
            int y;
            value=func_02008534(p->entries[i].current);
            text=func_020457B0(16,0x72);
            func_02008500(p->entries[i].current,p->names[i]);
            func_0201EFA4(p->formatter,0,value,5,2,1);
            format=func_02045EC0(p->bank,1);
            func_0201F250(p->formatter,text,format);
            if (player==i) ink=0x860; else ink=color;
            y=18*i+1;
            func_0201C7D0(func_02045770(window),5,18*i+1,p->names[i],p->font,ink);
            func_0201C7D0(func_02045770(window),70,y,text,p->font,ink);
            func_02045808(text);
            do { func_02045808(format); } while (0);
        }
      } while (0);
    }
    func_02045334(window);
    func_02045374(window);
    func_020409B4(func_02045730(window));
    return 1;
}
