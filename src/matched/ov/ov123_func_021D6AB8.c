/*
 * function: func_021D6AB8
 * address: 0x021D6AB8
 * packet: pkt_ov123_021D6AB8
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: declare out2 before out to place out at sp+0x3c, out2 at sp+0x40.
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_02049250 0x02049250 arm
 *   func_02049238 0x02049238 arm
 *   func_02020E60 0x02020E60 thumb
 *   func_02062A98 0x02062A98 arm
 *   func_02062A4C 0x02062A4C arm
 *   func_02082D44 0x02082D44 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02019D30 0x02019D30 thumb
 *   func_0201BB5C 0x0201BB5C thumb
 *   func_0201BABC 0x0201BABC thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Record { void *h; u16 x,y,a,b,age,c,d,e,f,g; };
struct Obj { u8 pad[0x40f4]; struct Record records[30]; };
struct ArcFile;
extern void *func_020490F4(u32 id, u16 heap);
extern void *func_02049250(struct ArcFile *arc, u32 member, u32 heap);
extern void func_02049238(void *);
extern u32 func_02020E60(u16, int);
extern void func_02062A98(void *, u8 **);
extern void func_02062A4C(void *, u8 **);
extern void func_02082D44(const void *, void *, u32);
extern void func_020307B0(void *);
extern int func_02019D30(u16, u8);
extern u32 func_0201BB5C(u32 species, u32 form, u32 half, u32 isEgg);
extern u32 func_0201BABC(u32 species, u32 form, u32 gender, u32 isEgg);
void func_021D6AB8(u8 *p)
{
    void *h;
    void *h2;
    void *buf;
    void *buf2;
    u8 *out2;
    u8 *out;
    int i,n,species,form,gender;
    u32 value;
    u16 id;
    h = func_020490F4(25, *(u16 *)(p+0x43c4));
    for (i = 0; i < 20; i++) {
        species = ((struct Obj *)p)->records[i].d;
        if (species) {
            buf = func_02049250(h,func_02020E60(species,2),*(u16 *)(p+0x43c4));
            func_02062A98(buf,&out);
            func_02082D44(*(void **)(out+12),p+0xbc+i*0x224,32);
            func_020307B0(buf);
            buf2 = func_02049250(h,func_02020E60(species,1),*(u16 *)(p+0x43c4));
            func_02062A4C(buf2,&out2);
            func_02082D44(*(void **)(out2+20),p+0xdc+i*0x224,512);
            func_020307B0(buf2);
        }
    }
    func_02049238(h);
    h2 = func_020490F4(7, *(u16 *)(p+0x43c4));
    for (i = 0; i < 10; i++) {
        n = i+20;
        species = ((struct Obj *)p)->records[n].d;
        if (species) {
            gender = ((struct Obj *)p)->records[n].f;
            form = func_02019D30(species,((struct Obj *)p)->records[n].e);
            value = func_0201BB5C(species,form,gender,0);
            id = func_0201BABC(species,form,gender,0);
            buf2 = func_02049250(h2,id,*(u16 *)(p+0x43c4));
            func_02062A4C(buf2,&out2);
            func_02082D44(*(void **)(out2+20),p+0xdc+n*0x224,512);
            func_020307B0(buf2);
            *(u32 *)(p+n*0x224+0x2dc) = value;
        }
    }
    func_02049238(h2);
}
