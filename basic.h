
// vim: ts=4:sts=4:sw=4:et

#ifndef AQUATIC_BASIC_H
#define AQUATIC_BASIC_H

#ifdef __cplusplus

#define AQUATIC_EXTERN_C extern "C" {
#define AQUATIC_END_C    }
#define AQUATIC_NAMESPACE     namespace aquatic {
#define AQUATIC_END_NAMESPACE }
#define AQUATIC_USING_NAMESPACE using namespace aquatic

#else // defined (__cplusplus)

#define AQUATIC_EXTERN_C
#define AQUATIC_END_C
#define AQUATIC_NAMESPACE
#define AQUATIC_END_NAMESPACE

#endif // defined (__cplusplus)

#endif // AQUATIC_BASIC_H

