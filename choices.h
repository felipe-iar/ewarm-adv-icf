#ifndef __CHOICES_H__
#define __CHOICES_H__

#ifdef USE_X
#warning Using X now...
__root const unsigned int __moduleX_begin @ ".blkX_start" = 0x5A5A5A5A;
__root const unsigned int __moduleX_end   @ ".blkX_end"   = 0xA5A5A5A5;
__root const unsigned int * slotX_start = &__moduleX_begin;
__root const unsigned int * slotX_end = &__moduleX_end;
extern int funX();
#endif

#ifdef USE_Y
#warning Using Y now...
__root const unsigned int __moduleY_begin @ ".blkY_start" = 0x5A5A5A5A;
__root const unsigned int __moduleY_end   @ ".blkY_end"   = 0xA5A5A5A5;
__root const unsigned int * slotY_start = &__moduleY_begin;
__root const unsigned int * slotY_end = &__moduleY_end;
extern int funY();
#endif

#ifdef USE_Z
#warning Using Z now...
__root const unsigned int __moduleZ_begin @ ".blkZ_start" = 0x5A5A5A5A;
__root const unsigned int __moduleZ_end   @ ".blkZ_end"   = 0xA5A5A5A5;
__root const unsigned int * slotZ_start = &__moduleZ_begin;
__root const unsigned int * slotZ_end = &__moduleZ_end;
extern int funZ();
#endif

#endif /* __CHOICES_H__ */