/*
 * file:     unit_02084614.c
 * unit:     yes
 * function: func_02084614, func_0208469C, func_020846AC, func_020846BC, func_020846CC, func_020846DC, func_020846EC, func_020846FC, func_0208470C, func_0208471C, func_0208472C, func_0208473C, func_0208474C
 * address:  0x02084614
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   OS_DisableIrqMask         0x02084998  arm
 *   OSi_IrqCallbackInfo       0x02150F38  data
 *   OSi_IrqCallbackInfoIndex  0x020A868C  data
 *   SDK_AUTOLOAD_DTCM_START   0x02FE0000  data
 *   OSi_IrqCallback  0x02084614  arm
 */
typedef unsigned long u32;

typedef unsigned short u16;

typedef int BOOL;

typedef u32 OSIntrMode;

typedef struct OSIrqCallbackInfo {
    void (*func)(void *);
    u32 enable;
    void *arg;
} OSIrqCallbackInfo;

extern u32 OS_DisableIrqMask(u32 intr);
void OSi_IrqCallback(int dmaNo);
void func_02084614(int index);
void func_0208469C(void);
void func_020846AC(void);
void func_020846BC(void);
void func_020846CC(void);
void func_020846DC(void);
void func_020846EC(void);
void func_020846FC(void);
void func_0208470C(void);
void func_0208471C(void);
void func_0208472C(void);
void func_0208473C(void);
void func_0208474C(void);
extern char SDK_AUTOLOAD_DTCM_START[];
extern OSIrqCallbackInfo OSi_IrqCallbackInfo[];
extern u16 OSi_IrqCallbackInfoIndex[];













/* HW_INTR_CHECK_BUF: the IRQ check word at DTCM + 0x3FF8. */
#define OSi_IRQ_CHECK_FLAG (*(volatile u32 *)((u32)SDK_AUTOLOAD_DTCM_START + 0x3FF8))













/*
 * sdk:      OSi_IrqCallback (os_irqtable.o)
 */
void func_02084614(int index)
{
    u32 imask = 1UL << OSi_IrqCallbackInfoIndex[index];
    void (*callback)(void *) = OSi_IrqCallbackInfo[index].func;

    OSi_IrqCallbackInfo[index].func = 0;
    if (callback) {
        callback(OSi_IrqCallbackInfo[index].arg);
    }

    OSi_IRQ_CHECK_FLAG |= imask;

    if (!OSi_IrqCallbackInfo[index].enable) {
        (void)OS_DisableIrqMask(imask);
    }
}













/*
 * note:     os_irqTable.o OSi_IrqDma0; libmatch named the address CameraStandbyCallback.
 */
void func_0208469C(void)
{
    OSi_IrqCallback(0);
}












/*
 * note:     os_irqTable.o OSi_IrqDma1; libmatch named the address DWC_EnableHotspot.
 */
void func_020846AC(void)
{
    OSi_IrqCallback(1);
}











/*
 * note:     os_irqTable.o wrapper; symbols_sdk names it OSi_IrqDma2.
 */
void func_020846BC(void)
{
    OSi_IrqCallback(2);
}










/*
 * note:     os_irqTable.o wrapper; symbols_sdk names it OSi_IrqDma3.
 */
void func_020846CC(void)
{
    OSi_IrqCallback(3);
}









/*
 * note:     os_irqTable.o wrapper; symbols_sdk names it OSi_IrqTimer0.
 */
void func_020846DC(void)
{
    OSi_IrqCallback(8);
}








/*
 * note:     os_irqTable.o wrapper; symbols_sdk names it OSi_IrqTimer1.
 */
void func_020846EC(void)
{
    OSi_IrqCallback(9);
}







/*
 * note:     os_irqTable.o wrapper; symbols_sdk names it OSi_IrqTimer2.
 */
void func_020846FC(void)
{
    OSi_IrqCallback(10);
}






/*
 * note:     os_irqTable.o wrapper; symbols_sdk names it OSi_IrqTimer3.
 */
void func_0208470C(void)
{
    OSi_IrqCallback(11);
}





/*
 * note:     os_irqTable.o wrapper; symbols_sdk names it OSi_IrqNDma0.
 */
void func_0208471C(void)
{
    OSi_IrqCallback(4);
}




/*
 * note:     os_irqTable.o wrapper; symbols_sdk names it OSi_IrqNDma1.
 */
void func_0208472C(void)
{
    OSi_IrqCallback(5);
}



/*
 * note:     os_irqTable.o wrapper; symbols_sdk names it OSi_IrqNDma2.
 */
void func_0208473C(void)
{
    OSi_IrqCallback(6);
}


/*
 * note:     os_irqTable.o wrapper; symbols_sdk names it OSi_IrqNDma3.
 */
void func_0208474C(void)
{
    OSi_IrqCallback(7);
}
