class point
{
      public:
                point(double init_x=0, double init_y=0); //set to x,y to 0 if no value declared
                void shift(double dx, double dy);
                double get_x() const;
                double get_y() const;
      private:
                double x;
                double y;
};
