/*
 * macros.h
 *
 *  Created on: 2013. 10. 14.
 *      Author: byungchul
 */

#ifndef MACROS_H_
#define MACROS_H_

#include <android/log.h>
//==============================
// Declarations
//==============================
#define LOG_TAG "cris.cpp"

#define DPRINTF(...)  __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)
#define IPRINTF(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
#define EPRINTF(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)



#endif /* MACROS_H_ */
