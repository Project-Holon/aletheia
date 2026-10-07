/*
 * file:     psel_p07.c
 * unit:     yes
 * function: func_021BAB78, func_021BABFC, func_021BAC0C, func_021BAC6C, func_021BAC70, func_021BAD68, func_021BAD80, func_021BADFC
 * address:  0x021BAB78
 * region:   ov223
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   file 0x021BCB00 data
 *   func_02030734 0x02030734 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02041090 0x02041090 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_02041570  0x02041570  arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049BDC 0x02049BDC arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02049238 0x02049238 arm
 *   func_020409B4 0x020409B4 arm
 *   site 0x021BCB00 data a4
 */
typedef unsigned short u16;

typedef unsigned char u8;

typedef unsigned int   u32;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern void func_02041090(unsigned,unsigned,unsigned,unsigned,u8,u8);
extern void func_02041B6C(unsigned);
extern int func_02041570(int, int);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern void func_02049BDC(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *,unsigned,unsigned,unsigned,unsigned,unsigned,u16);
extern void func_02049238(void *);
extern void func_020409B4(unsigned);
void func_021BAB78(u16 *p);
int func_021BABFC(void);
void func_021BAC0C(u16 *p);
void func_021BAC6C(void);
void func_021BAC70(const u16 *p);
void func_021BAD68(char *a0);
void func_021BAD80(u16 *p);
void func_021BADFC(char *a0);
extern const char file[];
extern const char site[];

/*
 * lever: cast the whole ternary to u16; declare col,row before index.
 */
void func_021BAB78(u16 *p)
{
    u8 col,row;
    u16 *buffer,index;
    buffer=func_02030734(*p,1536,1,file,0x951);
    index=0;
    for(row=0;row<24;row++) {
        for(col=0;col<32;col++) {
            u16 tile;
            tile=(u16)((row>=4 && row<20)?1:0);
            buffer[index]=tile|0xD000;
            index++;
        }
    }
    func_02041090(2,(unsigned)buffer,0,0,32,24);
    func_02041B6C(2);
    func_020307B0(buffer);
}


/*
 * Addresses are Black-image addresses.
 */
int func_021BABFC(void)
{
    return func_02041570(2, 0xd000);
}

void func_021BAC0C(u16 *p)
{
    void *object;
    object=func_020490F4(205,*p);
    func_02049BDC(object,6,4,256,256,256,*p);
    func_02049658(object,15,4,0,0,0,*p);
    func_020498F4(object,18,4,0,0,0,*p);
    func_02049238(object);
    func_020409B4(4);
}

void func_021BAC6C(void) {}

void func_021BAC70(const u16 *p)
{
    u16 *buffer;
    u8 x;
    u16 v;
    u8 y;
    u16 n;
    buffer=func_02030734(*p,1536,1,site,2463);
    n=0;
    for(y=0;y<24;y++)for(x=0;x<32;x++) {
        v=(y>=17&&y<23)?1:0;
        buffer[n]=v|0xd000;
        n++;
    }
    func_02041090(2,(u32)buffer,0,0,32,24);
    func_02041B6C(2);func_020307B0(buffer);
    buffer=func_02030734(*p,1536,1,site,2488);
    n=0;
    for(x=0;x<24;x++)for(y=0;y<32;y++) {
        v=(x>=17&&x<23)?1:0;
        buffer[n]=v;
        n++;
    }
    func_02041090(6,(u32)buffer,0,0,32,24);
    func_02041B6C(6);func_020307B0(buffer);
}


void func_021BAD68(char *a0)
{
    func_02041570(2, 0xd000);
    func_02041570(6, 0);
}

/*
 * Trailing ADFA halfword is zero alignment padding.
 */
void func_021BAD80(u16 *p)
{
    void *object;
    object = func_020490F4(205, *p);
    func_02049BDC(object, 7, 4, 256, 256, 256, *p);
    func_02049658(object, 16, 4, 0, 0, 0, *p);
    func_020498F4(object, 19, 4, 0, 0, 0, *p);
    func_020498F4(object, 20, 5, 0, 0, 0, *p);
    func_02049238(object);
    func_020409B4(4);
    func_020409B4(5);
}

void func_021BADFC(char *a0) {}
