/*
 * function: func_021E301C
 * address: 0x021E301C
 * packet: pkt_ov183_021E301C
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 02045CAC at +007A/+00AA/+0144; unit_02045C44.c omits its function entry. Scratch 45CAC-one.log EXACT 344 bytes, terminal exit 0; TU --suggest-split leaves caller out.
 * typedef unsigned char  u8;
 * typedef unsigned short u16;
 * typedef unsigned int   u32;
 * 
 * struct MsgEntry {
 *     u32 off;
 *     u16 len;
 *     u16 pad_06;
 * };
 * 
 * struct MsgFile {
 *     u16 langCount;
 *     u16 count;
 *     u32 unk_04;
 *     u32 unk_08;
 *     u32 langOff[1];
 * };
 * 
 * struct MsgBank {
 *     const struct MsgFile *file;
 *     void                 *base;
 *     struct MsgEntry       cache;
 *     u32                   origin;
 *     void                 *stream;
 *     u16                   heapId;
 *     u8                    langIndex;
 *     u8                    resident;
 * };
 * 
 * extern char g_020A7E8C[];
 * extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site,
 *                           u16 tag);
 * extern void func_020307B0(void *p);
 * extern void func_020495F4(void *stream, u32 size, void *dest);
 * extern void func_0204960C(void *stream, u32 pos);
 * extern void func_0204581C(void *dest);
 * extern void func_02045A00(void *dest, const void *src, u16 len);
 * extern void func_02045E04(void *dest, u32 index);
 * extern u8 func_020461B8(const void *file);
 * extern void func_02046110(struct MsgBank *bank);
 * extern void func_02046180(struct MsgBank *bank);
 * 
 * void func_02045CAC(struct MsgBank *bank, u32 index, void *dest)
 * {
 *     u32 size;
 *     struct MsgEntry *e;
 * 
 *     if (index >= bank->file->count) {
 *         func_0204581C(dest);
 *         return;
 *     }
 * 
 *     func_02046180(bank);
 * 
 *     if (bank->resident == 0) {
 *         u32 pos = bank->origin + bank->file->langOff[bank->langIndex];
 * 
 *         func_0204960C(bank->stream, pos + (index * 8 + 4));
 *         func_020495F4(bank->stream, 8, &bank->cache);
 *         e = &bank->cache;
 *     } else {
 *         e = (struct MsgEntry *)((u8 *)bank->base + 4) + index;
 *     }
 * 
 *     if (bank->resident == 0) {
 *         void *buf;
 * 
 *         size = e->len * 2;
 *         buf = sub_02030734((u16)((bank->heapId & 0x7fff) | 0x8000), size,
 *                            0, g_020A7E8C, 0xd6);
 *         if (buf != 0) {
 *             func_0204960C(bank->stream,
 *                           e->off + (bank->origin
 *                               + bank->file->langOff[bank->langIndex]));
 *             func_020495F4(bank->stream, size, buf);
 *             func_02045A00(dest, buf, e->len);
 *             func_020307B0(buf);
 *         }
 *     } else {
 *         func_02045A00(dest, (u8 *)bank->base + e->off, e->len);
 *     }
 * 
 *     func_02045E04(dest, index);
 * }
 * symbols:
 *   func_021FC20C 0x021FC20C thumb ov186
 *   func_021FC214 0x021FC214 thumb ov186
 *   func_021FC21C 0x021FC21C thumb ov186
 *   func_020457B0 0x020457B0 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_021FBE54 0x021FBE54 thumb ov186
 *   func_021FC124 0x021FC124 thumb ov186
 *   func_02045CAC 0x02045CAC arm
 *   func_0201EE0C 0x0201EE0C thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_021FB3BC 0x021FB3BC thumb ov186
 *   func_021FB378 0x021FB378 thumb ov186
 *   func_0200B910 0x0200B910 thumb
 *   func_0200D6D0 0x0200D6D0 thumb
 *   func_021FD12C 0x021FD12C thumb ov186
 *   func_0200D6EC 0x0200D6EC thumb
 *   func_021FD19C 0x021FD19C thumb ov186
 *   func_02045808 0x02045808 arm
 */
typedef unsigned short u16;
typedef struct Desc {short x,y,n;unsigned char flag,pad;} Desc;
typedef struct Triple {int a,b,c;} Triple;
extern int func_021FC20C(char *),func_021FC214(char *),func_021FC21C(char *);
typedef unsigned int   u32;
struct RecGet;
struct U16Vec;
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02082BCC(void *,int,unsigned),func_021FBE54(char *,unsigned,unsigned);
extern int func_021FC124(void *,int,Triple *);
extern void func_02045CAC(int,unsigned,void *),func_0201EE0C(void *,int,unsigned,unsigned,int,int),func_0201F250(void *,void *,void *);
extern void *func_021FB3BC(void *,void *,int,int,int,int,int,void *,u16);
extern void *func_021FB378(void *,int,int,int,int,int,int,int,void *,u16);
extern void *func_0200B910(void),*func_0200D6D0(const void *,u16);
extern void *func_021FD12C(int,int,u16);
extern u32 func_0200D6EC(struct RecGet *p);
extern void func_021FD19C(void *,int,void *),func_02045808(void *);
void func_021E301C(char *p,char *q)
{
    Triple t;
    Desc d;
    int h,c;
    void *a,*b,*s,*owner,*tmp;
    int i;
    unsigned offset;
    h=func_021FC20C(*(char **)(q+8));
    c=func_021FC214(*(char **)(q+8));
    a=(void *)func_021FC21C(*(char **)(q+8));
    b=func_020457B0(0x80,*(u16 *)(p+0x38));
    s=func_020457B0(0x80,*(u16 *)(p+0x38));
    func_02082BCC(&d,0,8);
    d.x=0x30;d.y=0x28;d.n=11;d.flag=1;
    func_021FBE54(*(char **)(q+8),1,*(u16 *)(p+0x38));
    func_021FC124(*(void **)(q+8),1,&t);
    for(i=0;i<3;i++) {
        offset=(i+1)*4;
        if(*(unsigned *)(*(unsigned *)(q+0x18)+offset)) {
            func_02045CAC(c,0x1a,s);
            func_0201EE0C(a,0,*(unsigned *)(*(unsigned *)(q+0x18)+offset+0x10),*(unsigned *)(*(unsigned *)(q+0x18)+offset+0x20),1,2);
            func_0201F250(a,b,s);
        }else func_02045CAC(c,9,b);
        *(void **)(p+i*4+0x14)=func_021FB3BC(&d,b,0xa0,1,*(int *)(q+4),*(int *)p,h,&t,*(u16 *)(p+0x38));
        d.y=d.y+0x28;
    }
    d.n=1;
    *(void **)(p+0x20)=func_021FB378(&d,4,0xa0,1,*(int *)(q+4),*(int *)p,h,c,&t,*(u16 *)(p+0x38));
    owner=func_0200B910();
    tmp=func_0200D6D0(owner,(*(u16 *)(p+0x38)&0x7fff)|0x8000);
    if(!*(void **)(p+8)) *(void **)(p+8)=func_021FD12C(*(int *)(q+8),*(int *)(p+4),*(u16 *)(p+0x38));
    func_02045CAC(c,0x5c,s);
    func_0201EE0C(a,0,(unsigned)tmp,func_0200D6EC(owner),1,2);
    func_0201F250(a,b,s);
    func_021FD19C(*(void **)(p+8),*(int *)(q+8),b);
    func_02045808(tmp);func_02045808(s);func_02045808(b);
}
