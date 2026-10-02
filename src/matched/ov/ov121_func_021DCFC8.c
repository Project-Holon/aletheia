/*
 * function: func_021DCFC8
 * address: 0x021DCFC8
 * packet: pkt_ov121_021DCFC8
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: const descriptor input places its loads before the outgoing heap store.
 * interfaces: D81C/D898 scalar stack words reproduce the aggregate layout; complete bodies and forwarding targets read no padding, key only low halfword.
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_021DA1BC 0x021DA1BC thumb ov121
 *   func_020490F4 0x020490F4 arm
 *   func_0204ABF0 0x0204ABF0 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_02049238 0x02049238 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B688 0x0204B688 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0202D7C8 0x0202D7C8 thumb
 *   func_0202D7D8 0x0202D7D8 thumb
 *   func_0202D898 0x0202D898 thumb
 *   func_0202D81C 0x0202D81C thumb
 *   func_0204B570 0x0204B570 arm
 *   d_021DFBB0 0x021DFBB0 data a4
 *   d_021DF99C 0x021DF99C data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef struct {u32 w[12];} Desc;
typedef struct {u32 w[30];} Config;
typedef struct {s16 x,y,z;u8 a,b;} Record;
extern char d_021DFBB0[];
extern const Config d_021DF99C;
extern void *func_02030734(u16,u32,u32,const char *,u32);
extern void *func_021DA1BC(void *,const char *,u32,u16,u8,u32,u32,int,u16);
extern void *func_020490F4(u32,u32);
extern int func_0204ABF0(void *,u32,u32,u16,u16);
extern int func_0204AF28(void *,u32,u32,u32);
extern int func_0204A6C8(void *,u32,u32,u32,u16);
extern void func_02049238(void *);
extern void func_02082BCC(void *,int,int);
extern void *func_0204B294(u32,u32,u32,u32,Record *,u16,u16);
extern void func_0204B688(void *,u32);
extern void func_0204B3DC(void *,u32);
extern void *func_0202D7C8(u16);
extern int func_0202D7D8(void *,u32,u32,u32,u32,u32,u32,u32,u16,u16);
extern int func_0202D898(u32,u32,u32,u32,u32,u32,u32,u32,u16);
extern int func_0202D81C(void *,u32,u32,u32,u32,u32,u32,u32,u32,u16);
extern void func_0204B570(void *,u32);
void *func_021DCFC8(const Desc *p,u16 heap)
{
    char *out;
    Config config;
    Record first;
    Record second;
    void *arc;
    void *arc2;
    out=func_02030734(heap,208,0,d_021DFBB0,0xcff);
    *(u32 *)(out+0x88)=p->w[5];
    *(u16 *)(out+0x94)=p->w[0];
    *(u16 *)(out+0x96)=p->w[1];
    *(Desc *)(out+0xa0)=*p;
    if(p->w[0]<4) {
        *(u32 *)(out+0x9c)=0;
        *(u32 *)(out+0x98)=0;
        *(u32 *)(out+0x84)=1;
    } else {
        *(u32 *)(out+0x9c)=4;
        *(u32 *)(out+0x98)=1;
        *(u32 *)(out+0x84)=0;
    }
    config=d_021DF99C;
    *(void **)out=func_021DA1BC((void *)1,(const char *)&config,5,*(u32 *)(out+0xa4),*(u32 *)(out+0xac),*(u32 *)(out+0xc8),*(u32 *)(out+0xc0),*(int *)(out+0xc4),heap);
    arc=func_020490F4(34,heap);
    *(int *)(out+4)=func_0204ABF0(arc,3,*(u32 *)(out+0x98),p->w[4]<<5,heap);
    *(int *)(out+12)=func_0204AF28(arc,33,36,heap);
    *(int *)(out+8)=func_0204A6C8(arc,12,0,*(u32 *)(out+0x98),heap);
    func_02049238(arc);
    func_02082BCC(&first,0,8);
    first.x=216;first.y=22;
    *(void **)(out+28)=func_0204B294(p->w[6],*(u32 *)(out+8),*(u32 *)(out+4),*(u32 *)(out+12),&first,*(u32 *)(out+0x98),heap);
    func_0204B688(*(void **)(out+28),0);
    func_0204B3DC(*(void **)(out+28),0);
    arc2=func_0202D7C8(heap);
    *(int *)(out+16)=func_0202D7D8(arc2,1,0,0,0,0,0,*(u32 *)(out+0x98),p->w[5]<<5,heap);
    *(int *)(out+24)=func_0202D898(1,0,0,0,0,0,2,*(u32 *)(out+0x98),heap);
    *(int *)(out+20)=func_0202D81C(arc2,1,0,0,0,0,0,0,*(u32 *)(out+0x98),heap);
    func_02049238(arc2);
    func_02082BCC(&second,0,8);
    second.x=184;second.y=112;second.b=p->w[0]&3;
    *(u32 *)(out+0x8c)=second.b;
    *(u32 *)(out+0x90)=p->w[1]&3;
    *(void **)(out+32)=func_0204B294(p->w[6],*(u32 *)(out+20),*(u32 *)(out+16),*(u32 *)(out+24),&second,*(u32 *)(out+0x98),heap);
    func_0204B570(*(void **)(out+32),2);
    func_0204B688(*(void **)(out+32),1);
    func_0204B3DC(*(void **)(out+32),0);
    return out;
}
