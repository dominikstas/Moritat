FROM gcc:latest

COPY . /usr/src/moritat

WORKDIR /usr/src/moritat

//to be fixed
RUN apt-get update && apt-get install -y cmake

RUN cmake .

RUN make

CMD ["./moritat"]
