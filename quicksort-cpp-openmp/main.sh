cmake -B build -S src

if [ $? -eq 0 ]; then
    cd build
    make

    if [ $? -eq 0 ]; then
	./main
    fi
fi

cd ..
