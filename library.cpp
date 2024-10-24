#include "Main.h"

JNIEXPORT jint JNICALL Java_Main_processInt
  (JNIEnv *evt, jobject obj, jint iVal) {
  return iVal +1;
}

JNIEXPORT jdouble JNICALL Java_Main_processDouble
  (JNIEnv *env, jobject obj, jdouble dVal) {
  return dVal*3;
}

JNIEXPORT jstring JNICALL Java_Main_processString
  (JNIEnv *env, jobject obj, jstring jString) {
  const char *str = env -> GetStringUTFChars( jString, NULL);

  int len = 0;
  const char *tmp = str;
  while (*tmp != '\0') {
    len++;
    tmp++;
  }

  char res[256] = "";

  int cnt = 0;
  while (len > 0) {
    tmp--;
    len--;
    res[cnt++] = *tmp;
  }

  env->ReleaseStringUTFChars(jString, str);

  return env->NewStringUTF(res);
}

JNIEXPORT jintArray JNICALL Java_Main_processArray
  (JNIEnv *env, jobject obj, jintArray jArr) {
  jsize length = env ->GetArrayLength(jArr);

  jint *elements = env->GetIntArrayElements(jArr, NULL);
  for (int i = 0; i < length; i++ ) {
    elements[i] *= 2;
  }

  env -> ReleaseIntArrayElements(jArr, elements, 0);
  return jArr;
}
