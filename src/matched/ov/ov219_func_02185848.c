/*
 * function: func_02185848
 * address: 0x02185848
 * packet: pkt_ov219_02185848
 * region: ov219
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0207AF1C 0x0207AF1C thumb
 *   func_0207AF00 0x0207AF00 thumb
 *   func_0207AF38 0x0207AF38 thumb
 *   func_0207B388 0x0207B388 arm
 *   d_020A1B38 0x020A1B38 data a2
 */
typedef unsigned short u16;
typedef struct {int words[9];} Matrix;
extern short d_020A1B38[];
extern void func_0207AF1C(Matrix *,int,int),func_0207AF00(Matrix *,int,int),func_0207AF38(Matrix *,int,int);
extern void func_0207B388(const Matrix *,const Matrix *,Matrix *);
static inline int sine(u16 a) {return d_020A1B38[(a>>4)*2];}
static inline int cosine(u16 a) {return d_020A1B38[(a>>4)*2+1];}
void func_02185848(Matrix *p,int *angles)
{
    Matrix temp;
    func_0207AF1C(p,sine(angles[1]),cosine(angles[1]));
    func_0207AF00(&temp,sine(angles[0]),cosine(angles[0]));
    func_0207B388(p,&temp,p);
    func_0207AF38(&temp,sine(angles[2]),cosine(angles[2]));
    func_0207B388(p,&temp,p);
}
