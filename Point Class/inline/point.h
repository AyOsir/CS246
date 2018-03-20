class point
{
    public:
                point(double init_x=0, double init_y=0)
                    { x = init_x; y=init_y; }
                void shift(double dx, double dy)
                    { x = x + dx; y=y+dy; }
                double get_x() const
                    {return x; }
                double get_y() const
                    {return y; }
      private:
                double x;
                double y;
};
