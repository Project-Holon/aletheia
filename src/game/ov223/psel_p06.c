/*
 * file:     psel_p06.c
 * unit:     yes
 * function: func_021BAAB8, func_021BAB74
 * address:  0x021BAAB8
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
 *   func_02040E78 0x02040E78 arm
 *   func_02043678 0x02043678 arm
 *   func_02043AF4 0x02043AF4 arm
 *   func_020437D4 0x020437D4 arm
 *   func_020437EC 0x020437EC arm
 *   func_02040B1C 0x02040B1C arm
 *   func_020437AC 0x020437AC arm
 */
struct Bmp;
struct Obj020437AC;
typedef unsigned short u16;

typedef unsigned int   u32;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern void func_02040E78(unsigned,void *,unsigned,unsigned);
extern struct Bmp *func_02043678(u32 width, u32 height, u32 depth, u16 heap);
extern void func_02043AF4(struct Bmp *b, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);
extern void *func_020437D4(const struct Bmp *bmp);
extern u32 func_020437EC(const struct Bmp *bmp);
extern void func_02040B1C(int index, const void *src, u32 size, u32 tile);
extern void func_020437AC(struct Obj020437AC *p);
void func_021BAAB8(u16 *p);
void func_021BAB74(int *a0);
extern const char file[];

void func_021BAAB8(u16 *p)
{
    u16 *buffer;
    void *bmp,*data;
    unsigned size;
    buffer=func_02030734(*p,32,1,file,0x92B);
    buffer[0]=0;buffer[1]=0;buffer[2]=0x7FFF;
    func_02040E78(2,buffer,32,0x1A0);
    func_02040E78(6,buffer,32,0);
    func_020307B0(buffer);
    bmp=func_02043678(2,1,32,*p);
    func_02043AF4(bmp,0,0,8,8,0);
    func_02043AF4(bmp,8,0,8,8,1);
    data=func_020437D4(bmp);size=func_020437EC(bmp);
    func_02040B1C(2,data,size,0);
    data=func_020437D4(bmp);size=func_020437EC(bmp);
    func_02040B1C(6,data,size,0);
    func_020437AC(bmp);
}

void func_021BAB74(int *a0) {}
