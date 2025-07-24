#pragma once

class IABase {
public:
    virtual ~IABase() = default;

    virtual void update() = 0;
    virtual void render() = 0;
    virtual void back_propagation() = 0;
    virtual void forward_propagation() = 0;
    virtual void init() = 0;
    virtual void train() = 0;
    virtual void train_split() = 0;
    virtual void predict() = 0;
    virtual void test() = 0;
    virtual void save() = 0;
    virtual void load() = 0;
    virtual void reset() = 0;

protected:
    IABase() = default;

private:
    IABase(const IABase&) = delete;
    IABase& operator=(const IABase&) = delete;
};