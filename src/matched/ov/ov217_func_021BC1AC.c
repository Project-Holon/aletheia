/*
 * function: RESEARCH_LIST_GetScrollbarY
 * address: 0x021BC1AC
 * packet: pkt_ov217_021BC1AC
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   RESEARCH_LIST_GetScrollY 0x021BC3AC thumb ov217
 *   RESEARCH_LIST_GetScrollRange 0x021BC40C thumb ov217
 *   _fflt 0x0209BDBC arm
 *   _fdiv 0x0209CE10 arm
 *   _fmul 0x0209C77C arm
 *   _fadd 0x0209C95C arm
 *   _ffix 0x0209C494 arm
 * 021BC40C forwards live r0 to 021BC6DC's +0x30 getter despite legacy void prototype.
 */
typedef unsigned int   u32;
extern int RESEARCH_LIST_GetScrollY(void);
extern int RESEARCH_LIST_GetScrollRange(void *p);
int RESEARCH_LIST_GetScrollbarY(void *p)
{
    int scroll;
    int height;
    float top;
    float span;
    int result;
    scroll=RESEARCH_LIST_GetScrollY();
    height=RESEARCH_LIST_GetScrollRange(p);
    scroll+=24;
    height+=24;
    top=(float)scroll;
    span=(float)height;
    result=(int)(32.0f+128.0f*(top/span));
    if(result<32)result=32;
    if(result>160)result=160;
    return result;
}
