SET(dirs vector)

FOREACH(dir ${dirs})
    ADD_SUBDIRECTORY(${dir})
ENDFOREACH()
  
