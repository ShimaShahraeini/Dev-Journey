using System;

namespace GameStore.Api.Entities;

public class Game
{
    public int ID { get; set; }
    public required string Name { get; set; }
    public int GenreID { get; set; } // foreign key
    public Genre? Genre{ get; set; } // navigation property
    public decimal Price { get; set; }
    public DateOnly ReleaseDate { get; set; }
}
