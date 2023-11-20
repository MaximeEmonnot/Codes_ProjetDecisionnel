\copy worldwide from 'C:\Users\ahmad\Documents\Nouveau dossier\Worldwide.csv' delimiter ';' csv header;

\copy usgs from 'C:\Users\ahmad\Documents\Nouveau dossier\USGS_Final_MagPos_modif_final2.csv' with encoding 'utf-8' delimiter ';' csv header;

-- Création de la table "Worldwide"
create table worldwide (
    tsunami numeric,
    year numeric,
    month numeric,
    day numeric,
    depth numeric,
    magnitude numeric,
    intensity varchar(255),
    country varchar(255),
    location_name varchar(255),
    latitude numeric,
    longitude numeric,
    region_code numeric,
    deaths numeric,
    missing numeric,
    injuries numeric,
    Damage_millions_dollars numeric,
    houses_destroyed numeric,
    houses_damaged numeric
);

-- Création de la table "TimeSeries"
create table timeSeries (
    year numeric,
    month numeric,
    day numeric,
    latitude numeric,
    longitude numeric,
    depth numeric,
    magnitude numeric
);


-- Création de la table "WorldwideTimeSeries" en copiant les données de "Worldwide"
create table worldwideTimeSeries as
select * from worldwide;

-- Création d'index pour optimiser les opérations de recherche
create index idx_year on worldwideTimeSeries(year);
create index idx_month on worldwideTimeSeries(month);
create index idx_day on worldwideTimeSeries(day);
create index idx_latitude on worldwideTimeSeries(latitude);
create index idx_longitude on worldwideTimeSeries(longitude);


-- Insérez les données de "TimeSeries" en vérifiant les conditions
insert into worldwideTimeSeries (tsunami, year, month, day, depth, magnitude, intensity, country, location_name, latitude, longitude, region_code, deaths, missing, injuries, Damage_millions_dollars, houses_destroyed, houses_damaged)
select
  null as tsunami,
  ts.year,
  ts.month,
  ts.day,
  ts.depth,
  ts.magnitude,
  null as intensity,
  null as country,
  null as location_name,
  ts.latitude,
  ts.longitude,
  null as region_code,
  null as deaths,
  null as missing,
  null as injuries,
  null as Damage_millions_dollars,
  null as houses_destroyed,
  null as houses_damaged
from timeSeries as ts
where not exists (
  select 1
  from worldwideTimeSeries as wts
  where wts.year = ts.year
    and wts.month = ts.month
    and wts.day = ts.day
) or (
  EXISTS (
    select 1
    from worldwideTimeSeries as wts
    where wts.year = ts.year
      and wts.month = ts.month
      and wts.day = ts.day
      and (wts.latitude <> ts.latitude or wts.longitude <> ts.longitude)
  )
);


-- Création de la table "usgs"
create table usgs (
    year numeric,
    month numeric,
    day numeric,
    place varchar(255),
    longitude numeric,
    latitude numeric,
    tsunami numeric,
    nst numeric,
    dmin numeric,
    rms numeric,
    gap numeric,
    mag numeric
);


-- Ajouter les colonnes manquantes à WorldwideTimeSeries
alter table worldwideTimeSeries
add column place varchar(255),
add column nst numeric,
add column dmin numeric,
add column rms numeric,
add column gap numeric;



-- Insérer les données de usgs dans WorldwideTimeSeries avec les conditions spécifiées
insert into WorldwideTimeSeries (
    tsunami,
    year,
    month,
    day,
    depth,
    magnitude,
    intensity,
    country,
    location_name,
    latitude,
    longitude,
    region_code,
    deaths,
    missing,
    injuries,
    Damage_millions_dollars,
    houses_destroyed,
    houses_damaged,
    place,
    nst,
    dmin,
    rms,
    gap
)
select
    usgs.tsunami,
    usgs.year,
    usgs.month,
    usgs.day,
    null as depth,
    usgs.mag,
    null as intensity,
    null as country,
    null as location_name,
    usgs.latitude,
    usgs.longitude,
    null as region_code,
    null as deaths,
    null as missing,
    null as injuries,
    null as Damage_millions_dollars,
    null as houses_destroyed,
    null as houses_damaged,
    usgs.place,
    usgs.nst,
    usgs.dmin,
    usgs.rms,
    usgs.gap
from usgs
where not exists (
    select 1
    from worldwideTimeSeries as wts
    where wts.year = usgs.year
      and wts.month = usgs.month
      and wts.day = usgs.day
) or (
    EXISTS (
        select 1
        from worldwideTimeSeries as wts
        where wts.year = usgs.year
          and wts.month = usgs.month
          and wts.day = usgs.day
          and (wts.latitude <> usgs.latitude or wts.longitude <> usgs.longitude)
    )
);