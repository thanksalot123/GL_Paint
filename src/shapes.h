#pragma once
class brushshapes 
{
public:
    virtual void drawShape(float x, float y, float r)
    {

    }
    virtual void drawHollow(float x, float y, float r) {
    
    }
    virtual ~brushshapes();
};

class circlebrush : public brushshapes 
{
public:
    circlebrush();
    void drawShape(float x, float y, float r);
    void drawHollow(float x, float y, float r);
    ~circlebrush();
};

class squarebrush : public brushshapes
{
public:
    squarebrush();
    void drawShape(float x, float y, float r);
    void drawHollow(float x, float y, float r);
    ~squarebrush()
    {

    }
};

class trianglebrush : public brushshapes
{
public:
    trianglebrush();
    void drawShape(float x, float y, float r);
    void drawHollow(float x, float y, float r);
    ~trianglebrush()
    {

    }
};