#define _GNU_SOURCE

#include <dlfcn.h>
#include <pthread.h>
#include <stdio.h>


#define dl_original(name) ({ \
    static __typeof__(name) * _original_ ## name = NULL; \
    if (! _original_ ## name) _original_ ## name = dlsym(RTLD_NEXT, #name); \
    _original_ ## name; \
})


int pthread_create (
    pthread_t *thread, const pthread_attr_t *attr,
    void *(*start_routine)(void *), void * arg
) {
    printf("intercepted pthread_create\n");
    return dl_original(pthread_create)(
        thread, attr, start_routine, arg
    );
}


int pthread_join (pthread_t thread, void **value_ptr) {
    printf("intercepted pthread_join\n");
    int ret = dl_original(pthread_join)(
        thread, value_ptr
    );
    printf("intercepted pthread_join returned %i\n", ret);
    return ret;
}
