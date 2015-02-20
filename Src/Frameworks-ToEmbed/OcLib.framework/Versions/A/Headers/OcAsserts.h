#ifndef __OcLib_OcAsserts_h__
#define __OcLib_OcAsserts_h__

#define OcAssertNot(var, val) NSAssert(var != val, @"%s: %s should not be %s!", __PRETTY_FUNCTION__, "var", "val")

#endif